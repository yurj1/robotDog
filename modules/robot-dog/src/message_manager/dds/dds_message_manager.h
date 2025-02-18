/**
 * @file    dds_message_manager.h
 * @author  hyzx
 * @date    2022-05-06
 * @version 1.0.0
 * @par     Copyright(c)
 * @license GNU General Public License (GPL)
 */

#pragma once

#if DDS_ENABLE

#include <mutex>
#include <thread>
#include <fastdds/dds/core/policy/QosPolicies.hpp>

#include "fastrtps/utils/IPLocator.h"
#include "fastdds/dds/topic/TypeSupport.hpp"
#include "dds_interface/EventsPubSubTypes.h"
#include "fastdds/dds/publisher/Publisher.hpp"
#include "fastdds/dds/publisher/DataWriter.hpp"
#include "dds_interface/ObuCmdMsgPubSubTypes.h"
#include "fastdds/dds/subscriber/DataReader.hpp"
#include "fastdds/dds/subscriber/SampleInfo.hpp"
#include "fastdds/dds/subscriber/Subscriber.hpp"
#include "fastdds/dds/domain/DomainParticipant.hpp"
#include "fastrtps/attributes/PublisherAttributes.h"
#include "fastdds/dds/publisher/qos/PublisherQos.hpp"
#include "fastrtps/attributes/SubscriberAttributes.h"
#include "fastdds/dds/publisher/qos/DataWriterQos.hpp"
#include "fastrtps/attributes/ParticipantAttributes.h"
#include "fastdds/dds/publisher/DataWriterListener.hpp"
#include "fastdds/dds/subscriber/qos/DataReaderQos.hpp"
#include "fastdds/dds/subscriber/DataReaderListener.hpp"
#include "fastdds/dds/domain/DomainParticipantFactory.hpp"
#include "fastdds/rtps/transport/TCPv4TransportDescriptor.h"
#include "fastdds/rtps/transport/UDPv4TransportDescriptor.h"

#include "message_manager/message_manager.h"

/**
 * @namespace athena::function
 * @brief athena::function
 */

namespace athena {
namespace function {
using namespace athena::common;
/**
 * @class DdsMessageManager
 * @brief DDS消息管理器.
 */
template <typename T>
class DdsMessageManager : public MessageManager<T>,
                          public eprosima::fastdds::dds::DataReaderListener {
public:
  DdsMessageManager() = default;
  virtual ~DdsMessageManager();

  /**
   * @brief     初始化。
   * @param[in] obu_url DDS组播信息.
   * @return    void.
   */
  void Init(T* t) override;

  bool Activate() override;
  bool DeActivate() override;

  /**
   * @brief     ObuCmdMsg消息发送.
   * @param[in] obu_cmd_msg
   * @return    void.
   */
  void PublishObuCmdMsgOutput(athena::interface::ObuCmdMsg msg) override;

protected:
  T* instance_;
  bool is_init_;
  bool is_active_;
  // 0 do_nothing ; 1 activate ; 2 deactivate
  MessageActionMode action_mode_;

  std::unique_ptr<std::thread> handle_message_thread_;

protected:
  std::mutex r_mutex_;
  std::mutex mode_mutex_;

  /**
   * @brief     线程运行函数.
   * @return    void.
   */
  void Run();

  void on_data_available(eprosima::fastdds::dds::DataReader* reader) override;

  /**
   * @brief     线程结束函数.
   * @return    void.
   */
  void Stop();

  void TaskStop();

  void TaskStart();

  void HandleEventsMessage(const ros2_interface::msg::Events* msg);

  void HandleObuCmdMsgMessage(const ros2_interface::msg::ObuCmdMsg* msg);

private:
  ros2_interface::msg::ObuCmdMsg obu_cmd_msg;
  eprosima::fastdds::dds::DomainParticipant* participant_;
  eprosima::fastdds::dds::Publisher* publisher_;

  eprosima::fastdds::dds::DataWriter* obu_cmd_msg_writer_;
  std::unique_ptr<eprosima::fastdds::dds::TypeSupport> obu_cmd_msg_type_;
  eprosima::fastdds::dds::Topic* obu_cmd_msg_topic_;

  eprosima::fastdds::dds::Subscriber* subscriber_;
  eprosima::fastdds::dds::Subscriber* command_subscriber_;
  eprosima::fastdds::dds::SampleInfo info_;

  eprosima::fastdds::dds::DataReader* events_reader_;
  std::unique_ptr<eprosima::fastdds::dds::TypeSupport> events_type_;
  eprosima::fastdds::dds::Topic* events_topic_;
  eprosima::fastdds::dds::DataReader* obu_cmd_msg_reader_;
  std::unique_ptr<eprosima::fastdds::dds::TypeSupport> obu_cmd_msg_type_;
  eprosima::fastdds::dds::Topic* obu_cmd_msg_topic_;
};
} // namespace function
} // namespace athena
#include "dds_message_manager.hpp"
#endif