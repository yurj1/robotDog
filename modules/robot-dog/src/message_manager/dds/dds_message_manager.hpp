/**
 * @file    dds_message_manager.hpp
 * @author  hyzx
 * @date    2022-05-06
 * @version 1.0.0
 * @par     Copyright(c)
 * @license GNU General Public License (GPL)
 */

#include "dds_message_manager.h"
#include "modules/common/macros/macros.h"
#include "modules/common/logging/logging.h"
#include "modules/common/math/euler_angles_zxy.h"

#if DDS_ENABLE
/**
 * @namespace athena::function
 * @brief athena::function
 */

namespace athena {
namespace function {
using namespace athena::common;
using namespace eprosima::fastdds::dds;
using namespace eprosima::fastdds::rtps;
using namespace eprosima::fastrtps::rtps;
template <typename T> void DdsMessageManager<T>::Init(T* t) {
  is_init_ = false;
  is_active_ = false;
  action_mode_ = MessageActionMode::DO_NOTHING;
  instance_ = t;

  DomainParticipantQos pqos;
  auto udp_transport = std::make_shared<UDPv4TransportDescriptor>();
  udp_transport->sendBufferSize = 0;
  udp_transport->receiveBufferSize = 0;
  udp_transport->TTL = 3;
  udp_transport->non_blocking_send = true;
  // Link the Transport Layer to the Participant.
  pqos.transport().user_transports.push_back(udp_transport);
  // Avoid using the default transport
  pqos.transport().use_builtin_transports = false;
  pqos.wire_protocol().builtin.discovery_config.discoveryProtocol =
      DiscoveryProtocol_t::SIMPLE;
  pqos.wire_protocol()
      .builtin.discovery_config.use_SIMPLE_EndpointDiscoveryProtocol = true;
  pqos.wire_protocol()
      .builtin.discovery_config.m_simpleEDP
      .use_PublicationReaderANDSubscriptionWriter = true;
  pqos.wire_protocol()
      .builtin.discovery_config.m_simpleEDP
      .use_PublicationWriterANDSubscriptionReader = true;
  pqos.name("Participant_pub");
  participant_ =
      DomainParticipantFactory::get_instance()->create_participant(200, pqos);
  if (participant_ == nullptr) {
    return;
  }
  DataWriterQos wqos;
  wqos.history().kind = KEEP_LAST_HISTORY_QOS;
  wqos.history().depth = 10;
  wqos.resource_limits().max_samples = 10000;
  // wqos.resource_limits().max_instances = 400;
  // wqos.resource_limits().allocated_samples = 100;
  wqos.reliable_writer_qos().times.heartbeatPeriod.seconds = 1;
  wqos.reliable_writer_qos().times.heartbeatPeriod.fraction(0);
  wqos.reliability().kind = RELIABLE_RELIABILITY_QOS;
  wqos.durability().kind = TRANSIENT_LOCAL_DURABILITY_QOS;
  wqos.endpoint().history_memory_policy = DYNAMIC_REUSABLE_MEMORY_MODE;
  wqos.publish_mode().kind = ASYNCHRONOUS_PUBLISH_MODE;
  // ObuCmdMsg
  obu_cmd_msg_type_.reset(new eprosima::fastdds::dds::TypeSupport(
      new ros2_interface::msg::ObuCmdMsgPubSubType()));
  obu_cmd_msg_type_->register_type(participant_);
  publisher_ = participant_->create_publisher(PUBLISHER_QOS_DEFAULT, nullptr);
  obu_cmd_msg_topic_ = participant_->create_topic(
      "rt/function/emergency_stop/ObuCmdMsg",
      obu_cmd_msg_type_->get_type_name(), TOPIC_QOS_DEFAULT);
  obu_cmd_msg_writer_ =
      publisher_->create_datawriter(obu_cmd_msg_topic_, wqos, nullptr);

  DataReaderQos rqos;
  rqos.history().kind = KEEP_LAST_HISTORY_QOS;
  rqos.history().depth = 10;
  rqos.resource_limits().max_samples = 10000;
  rqos.reliable_reader_qos().times.heartbeatResponseDelay.seconds = 1;
  rqos.reliable_reader_qos().times.heartbeatResponseDelay.fraction(0);
  // rqos.durability().kind = TRANSIENT_LOCAL_DURABILITY_QOS;
  rqos.reliability().kind = RELIABLE_RELIABILITY_QOS;
  rqos.endpoint().history_memory_policy = DYNAMIC_REUSABLE_MEMORY_MODE;

  command_subscriber_ =
      participant_->create_subscriber(SUBSCRIBER_QOS_DEFAULT, nullptr);
  subscriber_ =
      participant_->create_subscriber(SUBSCRIBER_QOS_DEFAULT, nullptr);

  events_type_.reset(new eprosima::fastdds::dds::TypeSupport(
      new ros2_interface::msg::EventsPubSubType()));
  events_type_->register_type(participant_);
  events_topic_ = participant_->create_topic("rt/state_manager/Events",
                                             events_type_->get_type_name(),
                                             TOPIC_QOS_DEFAULT);

  obu_cmd_msg_type_.reset(new eprosima::fastdds::dds::TypeSupport(
      new ros2_interface::msg::ObuCmdMsgPubSubType()));
  obu_cmd_msg_type_->register_type(participant_);
  obu_cmd_msg_topic_ = participant_->create_topic(
      "rt/state_manager/ObuCmdMsg", obu_cmd_msg_type_->get_type_name(),
      TOPIC_QOS_DEFAULT);
  obu_cmd_msg_reader_ =
      command_subscriber_->create_datareader(obu_cmd_msg_topic_, rqos, this);

  // 线程执行开始
  handle_message_thread_.reset(new std::thread([this] { Run(); }));
  if (handle_message_thread_ == nullptr) {
    AERROR << "Unable to create handle_message_thread thread.";
    return;
  }
  is_init_ = true;
}

template <typename T> bool DdsMessageManager<T>::Activate() {
  std::unique_lock<std::mutex> lock(mode_mutex_);
  if (is_active_ == true) {
    std::cout << "already start" << std::endl;
    action_mode_ = MessageActionMode::DO_NOTHING;
    return false;
  } else {
    action_mode_ = MessageActionMode::TO_ACTIVATE;
  }
  return true;
}

template <typename T> bool DdsMessageManager<T>::DeActivate() {
  std::unique_lock<std::mutex> lock(mode_mutex_);
  if (is_active_ == false) {
    std::cout << "already stop" << std::endl;
    action_mode_ = MessageActionMode::DO_NOTHING;
    return false;
  } else {
    action_mode_ = MessageActionMode::TO_DEACTIVATE;
  }
  return true;
}

template <typename T> void DdsMessageManager<T>::TaskStart() {
  if (is_active_ == true) {
    return;
  }
  DataReaderQos rqos;
  rqos.history().kind = KEEP_LAST_HISTORY_QOS;
  rqos.history().depth = 30;
  rqos.resource_limits().max_samples = 5000;
  rqos.resource_limits().allocated_samples = 400;
  rqos.resource_limits().max_instances = 100;
  // rqos.durability().kind = TRANSIENT_LOCAL_DURABILITY_QOS;
  rqos.reliability().kind = RELIABLE_RELIABILITY_QOS;
  rqos.endpoint().history_memory_policy = DYNAMIC_REUSABLE_MEMORY_MODE;
  events_reader_ = subscriber_->create_datareader(events_topic_, rqos, this);
  std::cout << "dds activate" << std::endl;
  action_mode_ = MessageActionMode::DO_NOTHING;
  is_active_ = true;
  return;
}

template <typename T> void DdsMessageManager<T>::TaskStop() {
  // std::lock_guard<std::mutex> lock(r_mutex_);
  if (is_active_ == false) {
    return;
  }
  subscriber_->delete_contained_entities();
  std::cout << "dds deactivate" << std::endl;
  action_mode_ = MessageActionMode::DO_NOTHING;
  is_active_ = false;
  return;
}
template <typename T>
void DdsMessageManager<T>::PublishObuCmdMsgOutput(
    athena::interface::ObuCmdMsg msg) {
  if (is_init_ == false)
    return;
  ros2_interface::msg::ObuCmdMsg obu_cmd_msg;
  MESSAGE_DDS_HEADER_ASSIGN(ros2_interface::msg, obu_cmd_msg)
  obu_cmd_msg.id() = msg.id();
  obu_cmd_msg.name() = msg.name();
  std::vector<ros2_interface::msg::ObuCmd> dds_obu_cmd_list;
  std::vector<athena::interface::ObuCmd> athena_obu_cmd_list;
  msg.obu_cmd_list(athena_obu_cmd_list);
  for (auto it_obu_cmd_list : athena_obu_cmd_list) {
    ros2_interface::msg::ObuCmd obu_cmd_msg_obu_cmd;
    obu_cmd_msg_obu_cmd.code() = it_obu_cmd_list.code();
    obu_cmd_msg_obu_cmd.val() = it_obu_cmd_list.val();
    dds_obu_cmd_list.emplace_back(obu_cmd_msg_obu_cmd);
  }
  obu_cmd_msg.obu_cmd_list() = dds_obu_cmd_list;

  obu_cmd_msg_writer_->write(&obu_cmd_msg);
}

template <typename T>
void DdsMessageManager<T>::HandleEventsMessage(
    const ros2_interface::msg::Events* msg) {
  athena::interface::Events events;

  instance_->HandleEvents(events);
}

template <typename T>
void DdsMessageManager<T>::HandleObuCmdMsgMessage(
    const ros2_interface::msg::ObuCmdMsg* msg) {
  athena::interface::ObuCmdMsg obu_cmd_msg;
  MESSAGE_DDS_HEADER_PARSER(obu_cmd_msg)
  obu_cmd_msg.set_id(msg->id());
  obu_cmd_msg.set_name(msg->name());
  std::vector<athena::interface::ObuCmd> obu_cmd_list;
  for (auto it_obu_cmd_list : msg->obu_cmd_list()) {
    athena::interface::ObuCmd obu_cmd_msg_obu_cmd;
    obu_cmd_msg_obu_cmd.set_code(it_obu_cmd_list.code());
    obu_cmd_msg_obu_cmd.set_val(it_obu_cmd_list.val());
    obu_cmd_list.emplace_back(obu_cmd_msg_obu_cmd);
  }
  obu_cmd_msg.set_obu_cmd_list(&obu_cmd_list);

  instance_->HandleObuCmdMsgInput(obu_cmd_msg);
}

template <typename T>
void DdsMessageManager<T>::on_data_available(
    eprosima::fastdds::dds::DataReader* reader) {
  std::lock_guard<std::mutex> lock(r_mutex_);
  if (is_init_ == false)
    return;
  if (!reader->get_topicdescription()->get_name().compare(
          "rt/vui_client/ObuCmdMsg")) {

    ros2_interface::msg::ObuCmdMsg msg;
    eprosima::fastdds::dds::SampleInfo info;
    if (obu_cmd_msg_reader_->take_next_sample(&msg, &info) ==
        ReturnCode_t::RETCODE_OK) {
      HandleObuCmdMsgMessage(&msg);
    }
    return;
  }

  if (is_active_ == false) {
    return;
  }
  if (!reader->get_topicdescription()->get_name().compare(
          "rt/state_manager/Events")) {

    ros2_interface::msg::Events msg;
    eprosima::fastdds::dds::SampleInfo info;
    if (events_reader_->take_next_sample(&msg, &info) ==
        ReturnCode_t::RETCODE_OK) {
      HandleEventsMessage(&msg);
    }
  }
  return;
}
template <typename T> DdsMessageManager<T>::~DdsMessageManager() {
  participant_->delete_contained_entities();
  DomainParticipantFactory::get_instance()->delete_participant(participant_);
}
template <typename T> void DdsMessageManager<T>::Run() {
  while (true) {
    std::unique_lock<std::mutex> lock(mode_mutex_);
    switch (action_mode_) {
    case MessageActionMode::DO_NOTHING:
      /* code sleep */
      break;
    case MessageActionMode::TO_ACTIVATE:
      TaskStart();
      break;
    case MessageActionMode::TO_DEACTIVATE:
      TaskStop();
      break;
    default:
      // sleep
      break;
    }
    lock.unlock();
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
  }
}

template <typename T> void DdsMessageManager<T>::Stop() {}
} // namespace function
} // namespace athena
#endif
