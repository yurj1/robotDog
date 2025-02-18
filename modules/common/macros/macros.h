

#pragma once

#include <iostream>
#include <memory>
#include <mutex>
#include <type_traits>
#include <utility>

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
using namespace boost::property_tree;

#include "modules/common/base/macros.h"

DEFINE_TYPE_TRAIT(HasShutdown, Shutdown)

template <typename T>
typename std::enable_if<HasShutdown<T>::value>::type CallShutdown(T *instance)
{
  instance->Shutdown();
}

template <typename T>
typename std::enable_if<!HasShutdown<T>::value>::type
CallShutdown(T *instance)
{
  (void)instance;
}

// There must be many copy-paste versions of these macros which are same
// things, undefine them to avoid conflict.
#undef UNUSED
#undef DISALLOW_COPY_AND_ASSIGN

#define UNUSED(param) (void)param

#define DISALLOW_COPY_AND_ASSIGN(classname) \
  classname(const classname &) = delete;    \
  classname &operator=(const classname &) = delete;

#define LOGGING_INIT(conf_ptr, json_obj)                              \
  LoggingConf logging_conf;                                           \
                                                                      \
  logging_conf.app_name = json_obj["app_name"];                       \
  logging_conf.description = json_obj["description"];                 \
  logging_conf.file_path = json_obj["log_file_path"];                 \
  logging_conf.log_level = json_obj["log_level"];                     \
  logging_conf.logging_data_enable = json_obj["logging_data_enable"]; \
  Logging::Init(logging_conf);                                        \
  conf_ptr->set_logging_conf(logging_conf);

#define MONITOR_LOGGING_INIT(conf_ptr, json_obj)                      \
  LoggingConf logging_conf;                                           \
                                                                      \
  logging_conf.app_name = json_obj->app_name();                       \
  logging_conf.description = json_obj->description();                 \
  logging_conf.file_path = json_obj->log_file_path();                 \
  logging_conf.log_level = json_obj->log_level();                     \
  logging_conf.logging_data_enable = json_obj->logging_data_enable(); \
  Logging::Init(logging_conf);

#define MESSAGE_INIT(conf_ptr, json_obj)                                       \
  std::map<std::string, athena::common::Message> messages;                     \
  uint32_t active_message_size = json_obj["message"]["active_message"].size(); \
  for (uint32_t i = 0; i < active_message_size; i++)                           \
  {                                                                            \
    athena::common::Message message;                                           \
    uint32_t index = json_obj["message"]["active_message"][i];                 \
    message.type = (athena::common::MessageType)                               \
        json_obj["message"]["message_info"][index]["type"];                    \
    message.name = json_obj["message"]["message_info"][index]["name"];         \
    message.url = json_obj["message"]["message_info"][index]["url"];           \
    messages.insert(std::pair<std::string, athena::common::Message>(           \
        message.name, message));                                               \
  }                                                                            \
                                                                               \
  conf_ptr->set_messages(messages);                                            \
                                                                               \
  MessagesInit();                                                              \
                                                                               \
  uint32_t message_status_size = json_obj["status"]["message_status"].size();  \
                                                                               \
  for (uint32_t i = 0; i < message_status_size; i++)                           \
  {                                                                            \
    MessageStatus message_status;                                              \
                                                                               \
    message_status.set_name(json_obj["status"]["message_status"][i]["name"]);  \
    message_status.set_monitor(                                                \
        json_obj["status"]["message_status"][i]["monitor"]);                   \
    message_status.set_initialized(false);                                     \
    message_status.set_type(json_obj["status"]["message_status"][i]["type"]);  \
    message_status.set_mode(json_obj["status"]["message_status"][i]["mode"]);  \
    message_status.set_period(                                                 \
        (double)json_obj["status"]["message_status"][i]["period"]);            \
    message_status.set_init_timeout(                                           \
        (double)json_obj["status"]["message_status"][i]["init_timeout"]);      \
    message_status.set_max_miss_num(                                           \
        json_obj["status"]["message_status"][i]["max_miss_num"]);              \
    message_status.set_last_time(TimeTool::Now2Ms());                          \
    message_status.set_status(MessageStatus::Status::INITIALIZATION);          \
    message_status_.insert(std::pair<std::string, MessageStatus>(              \
        message_status.name(), message_status));                               \
  }

#define MODULE(T, keyname) it->second.get<T>(keyname)
#define FAULTTYPE(T, keyname) sub_it->second.get<T>(keyname)
#define FAULT(T, keyname) sub_sub_it->second.get<T>(keyname)
#define PRINT_FAULT(name, num) std::cout << ++num << "\t" << name << std::endl
#ifdef SAFEGUARD_MODE
#define THIS_FAULTCODESET athena::interface::SafeFaultCodeSet
#define DO_SPECIAL_MODE_ACTION(faultset, module)                                                                    \
  for (boost::property_tree::ptree::iterator it = modules.begin(); it != modules.end(); ++it)                       \
  {                                                                                                                 \
    std::string target = MODULE(string, "target");                                                                  \
    std::string timeout_fault = MODULE(string, "timeout_fault");                                                    \
    std::string interrupt_fault = MODULE(string, "interrupt_fault");                                                \
    std::string topicname(MODULE(string, "topic_name"));                                                            \
    bool match = (0 == target.compare(module));                                                                     \
    if (topicname.length() > 0 && !match)                                                                           \
    {                                                                                                               \
      faultset->add_topicnametotimeout_map(topicname, timeout_fault);                                               \
      faultset->add_topicnametointerrupt_map(topicname, interrupt_fault);                                           \
      faultset->add_channel_watch_list(topicname);                                                                  \
      faultset->add_module_watch_list(target);                                                                      \
    }                                                                                                               \
    boost::property_tree::ptree faultcode = it->second.get_child("faultcode");                                      \
    for (boost::property_tree::ptree::iterator sub_it = faultcode.begin(); sub_it != faultcode.end(); ++sub_it)     \
    {                                                                                                               \
      boost::property_tree::ptree list = sub_it->second.get_child("list");                                          \
      for (boost::property_tree::ptree::iterator sub_sub_it = list.begin(); sub_sub_it != list.end(); ++sub_sub_it) \
      {                                                                                                             \
        int enable = FAULT(int, "enable");                                                                          \
        if (enable == -1)                                                                                           \
        {                                                                                                           \
          continue;                                                                                                 \
        }                                                                                                           \
        athena::interface::FaultProperty faulttype;                                                                 \
        uint32_t code = FAULT(uint32_t, "code");                                                                    \
        std::string name = FAULT(string, "name");                                                                   \
        PRINT_FAULT(name, num);                                                                                     \
        faulttype.set_name(name);                                                                                   \
        faulttype.set_code(code);                                                                                   \
        faulttype.set_enable(enable);                                                                               \
        faulttype.set_condition_0(FAULT(int, "condition_0"));                                                       \
        faulttype.set_condition_f(FAULT(int, "condition_f"));                                                       \
        faultset->add_faulttype_hashmap(code, faulttype);                                                           \
      }                                                                                                             \
    }                                                                                                               \
  }
#else
#ifdef STATE_FUNCTION_MODE
#define THIS_FAULTCODESET athena::interface::SafeFaultCodeSet
#define DO_SPECIAL_MODE_ACTION(faultset, module)                                                                    \
  std::cout << "STATE_FUNCTION_MODE" << std::endl;                                                                  \
  for (boost::property_tree::ptree::iterator it = modules.begin(); it != modules.end(); ++it)                       \
  {                                                                                                                 \
    std::string target = MODULE(string, "target");                                                                  \
    boost::property_tree::ptree faultcode = it->second.get_child("faultcode");                                      \
    for (boost::property_tree::ptree::iterator sub_it = faultcode.begin(); sub_it != faultcode.end(); ++sub_it)     \
    {                                                                                                               \
      boost::property_tree::ptree list = sub_it->second.get_child("list");                                          \
      for (boost::property_tree::ptree::iterator sub_sub_it = list.begin(); sub_sub_it != list.end(); ++sub_sub_it) \
      {                                                                                                             \
        int enable = FAULT(int, "enable");                                                                          \
        if (enable == -1)                                                                                           \
        {                                                                                                           \
          continue;                                                                                                 \
        }                                                                                                           \
        athena::interface::FaultProperty faulttype;                                                                 \
        uint32_t code = FAULT(uint32_t, "code");                                                                    \
        std::string name = FAULT(string, "name");                                                                   \
        PRINT_FAULT(name, num);                                                                                     \
        faulttype.set_name(name);                                                                                   \
        faulttype.set_code(code);                                                                                   \
        faulttype.set_enable(enable);                                                                               \
        faulttype.set_condition_0(FAULT(int, "condition_0"));                                                       \
        faulttype.set_condition_f(FAULT(int, "condition_f"));                                                       \
        faultset->add_faulttype_hashmap(code, faulttype);                                                           \
      }                                                                                                             \
    }                                                                                                               \
  }                                                                                                                 \
  faultset->enable_all_watches(true)
#else
#define THIS_FAULTCODESET athena::interface::FaultCodeSet
#define DO_SPECIAL_MODE_ACTION(faultset, module) faultset->enable_all_watches(true)
#endif
#endif
#define FAULTCODE_INIT(json_path, module, faultset, send_callback,                                                    \
                       fault_callback)                                                                                \
  boost::property_tree::ptree root;                                                                                   \
  boost::property_tree::read_json<boost::property_tree::ptree>(json_path, root);                                      \
  boost::property_tree::ptree modules = root.get_child("modules");                                                    \
  int num = 0;                                                                                                        \
  for (boost::property_tree::ptree::iterator it = modules.begin(); it != modules.end(); ++it)                         \
  {                                                                                                                   \
    string target = MODULE(string, "target");                                                                         \
    bool match = (0 == target.compare(module));                                                                       \
    if (false == match)                                                                                               \
    {                                                                                                                 \
      continue;                                                                                                       \
    }                                                                                                                 \
    int target_id = MODULE(int, "target_id");                                                                         \
    bool fault_enable = MODULE(bool, "fault_enable");                                                                 \
    bool heart_enable = MODULE(bool, "heart_enable");                                                                 \
    int heart_period = MODULE(int, "heart_period");                                                                   \
    faultset = new THIS_FAULTCODESET(                                                                                 \
        target_id, (heart_enable == true) ? send_callback : nullptr,                                                  \
        heart_period);                                                                                                \
    if (fault_enable == true)                                                                                         \
    {                                                                                                                 \
      boost::property_tree::ptree faultcode = it->second.get_child("faultcode");                                      \
      for (boost::property_tree::ptree::iterator sub_it = faultcode.begin(); sub_it != faultcode.end(); ++sub_it)     \
      {                                                                                                               \
        int type = FAULTTYPE(int, "fault_type");                                                                      \
        boost::property_tree::ptree list = sub_it->second.get_child("list");                                          \
        for (boost::property_tree::ptree::iterator sub_sub_it = list.begin(); sub_sub_it != list.end(); ++sub_sub_it) \
        {                                                                                                             \
          int enable = FAULT(int, "enable");                                                                          \
          std::string black_or_white;                                                                                 \
          if (enable == -1)                                                                                           \
          {                                                                                                           \
            continue;                                                                                                 \
          }                                                                                                           \
          athena::interface::FaultProperty faulttype;                                                                 \
          faulttype.set_code(FAULT(int, "code"));                                                                     \
          faulttype.set_name(FAULT(string, "name"));                                                                  \
          faulttype.set_enable(enable);                                                                               \
          switch (type)                                                                                               \
          {                                                                                                           \
          case athena::interface::FAULT_TYPE::DATA_TIMEOUT:                                                           \
          case athena::interface::FAULT_TYPE::DATA_INTERRUPT:                                                         \
          case athena::interface::FAULT_TYPE::TIME_ERROR:                                                             \
          case athena::interface::FAULT_TYPE::FEEDBACK_ABNORMAL:                                                      \
          case athena::interface::FAULT_TYPE::CALCULATE_TIMEOUT:                                                      \
            faulttype.set_timeout(FAULT(int, "timeout"));                                                             \
            break;                                                                                                    \
          case athena::interface::FAULT_TYPE::DATA_LOST:                                                              \
            faulttype.set_max_count(FAULT(int, "max_count"));                                                         \
            break;                                                                                                    \
          case athena::interface::FAULT_TYPE::DATA_ERROR:                                                             \
          case athena::interface::FAULT_TYPE::INIT_FAILED:                                                            \
          case athena::interface::FAULT_TYPE::CALCULATE_FAILED:                                                       \
          case athena::interface::FAULT_TYPE::DATA_ABNORMAL:                                                          \
            black_or_white = FAULT(string, "black_or_white");                                                         \
            faulttype.set_black_or_white(black_or_white);                                                             \
            if (0 != black_or_white.compare("white_p8") &&                                                            \
                0 != black_or_white.compare("black_p8"))                                                              \
            {                                                                                                         \
              faulttype.set_upper(FAULT(double, "upper"));                                                            \
            }                                                                                                         \
            if (0 != black_or_white.compare("white_n8") &&                                                            \
                0 != black_or_white.compare("black_n8"))                                                              \
            {                                                                                                         \
              faulttype.set_lower(FAULT(double, "lower"));                                                            \
            }                                                                                                         \
            faulttype.set_timeout(FAULT(int, "timeout"));                                                             \
            break;                                                                                                    \
          }                                                                                                           \
          PRINT_FAULT(faulttype.name(), num);                                                                         \
          auto fault_object =                                                                                         \
              athena::interface::FaultClientFactory::RegisterFaultClients(                                            \
                  type, fault_callback, faulttype.name(), faulttype.code(),                                           \
                  faulttype.timeout(), faulttype.max_count(),                                                         \
                  faulttype.black_or_white(), faulttype.lower(),                                                      \
                  faulttype.upper());                                                                                 \
          fault_object->set_enable(enable);                                                                           \
          faultset->add_watch_map(faulttype.name(), fault_object);                                                    \
        }                                                                                                             \
      }                                                                                                               \
    }                                                                                                                 \
    if (true == match)                                                                                                \
    {                                                                                                                 \
      break;                                                                                                          \
    }                                                                                                                 \
  }                                                                                                                   \
  num = 0;                                                                                                            \
  DO_SPECIAL_MODE_ACTION(faultset, module);

#define ENABLE_SWITCH(str, bool)                         \
  if (faultcodeset_->get_watch().count(str) > 0 &&       \
      faultcodeset_->get_watch()[str]->enable() != bool) \
  {                                                      \
    faultcodeset_->get_watch()[str]->set_enable(bool);   \
  }

#define CHECK_FAULT(str, value)                                \
  if (faultcodeset_->get_watch().count(str) > 0)               \
  {                                                            \
    if (faultcodeset_->get_watch()[str]->enable() == true)     \
    {                                                          \
      faultcodeset_->get_watch()[str]->set_check_value(value); \
    }                                                          \
  }

#define MESSAGE_HEADER_PARSER(obj)                 \
  athena::interface::Header header;                \
  uint32_t seq = (uint32_t)msg->header.seq;        \
  header.set_seq(seq);                             \
  athena::interface::Time interface_time;          \
  interface_time.set_sec(msg->header.stamp.sec);   \
  interface_time.set_nsec(msg->header.stamp.nsec); \
  header.set_stamp(interface_time);                \
  header.set_frame_id(msg->header.frame_id);       \
  obj.set_header(header);

#define MESSAGE_DDS_HEADER_PARSER(obj)                   \
  athena::interface::Header header;                      \
  uint32_t seq = (uint32_t)msg->header().seq();          \
  header.set_seq(seq);                                   \
  athena::interface::Time interface_time;                \
  interface_time.set_sec(msg->header().stamp().sec());   \
  interface_time.set_nsec(msg->header().stamp().nsec()); \
  header.set_stamp(interface_time);                      \
  header.set_frame_id(msg->header().frame_id());         \
  obj.set_header(header);

#define MESSAGE_HEADER_ASSIGN(param, obj)          \
  param::Header header;                            \
  header.stamp.sec = msg.header().stamp().sec();   \
  header.stamp.nsec = msg.header().stamp().nsec(); \
  header.seq = msg.header().seq();                 \
  header.frame_id = msg.header().frame_id();       \
  obj.header = header;

#define MESSAGE_DDS_HEADER_ASSIGN(param, obj)          \
  param::Header header;                                \
  header.stamp().sec() = msg.header().stamp().sec();   \
  header.stamp().nsec() = msg.header().stamp().nsec(); \
  header.seq() = msg.header().seq();                   \
  header.frame_id() = msg.header().frame_id();         \
  obj.header() = header;

#define DDS_FAULTS_PARSER(param, obj)                        \
  obj.version() = msg.version();                             \
  std::vector<param##_interface::msg::Fault> param##_faults; \
  std::vector<athena::interface::Fault> interface_faults;    \
  msg.faults(interface_faults);                              \
  for (auto it : interface_faults)                           \
  {                                                          \
    param##_interface::msg::Fault fault;                     \
    fault.timestamp().sec() = it.timestamp().sec();          \
    fault.timestamp().nsec() = it.timestamp().nsec();        \
    fault.code() = it.code();                                \
    fault.reason() = it.reason();                            \
    param##_faults.emplace_back(fault);                      \
  }                                                          \
  obj.faults() = param##_faults;                             \
  obj.app_id() = msg.app_id();                               \
  obj.is_active() = msg.is_active();

#define FAULTS_PARSER(param, obj)                         \
  obj.version = msg.version();                            \
  std::vector<param##_interface::Fault> param##_faults;   \
  std::vector<athena::interface::Fault> interface_faults; \
  msg.faults(interface_faults);                           \
  for (auto it : interface_faults)                        \
  {                                                       \
    param##_interface::Fault fault;                       \
    fault.timestamp.sec = it.timestamp().sec();           \
    fault.timestamp.nsec = it.timestamp().nsec();         \
    fault.code = it.code();                               \
    fault.reason = it.reason();                           \
    param##_faults.emplace_back(fault);                   \
  }                                                       \
  obj.faults_size = param##_faults.size();                \
  obj.app_id = msg.app_id();                              \
  obj.is_active = msg.is_active();                        \
  obj.faults = param##_faults;

// ros1
#define FAULTS_PARSER_1(param, obj)                       \
  obj.version = msg.version();                            \
  std::vector<param##_interface::Fault> param##_faults;   \
  std::vector<athena::interface::Fault> interface_faults; \
  msg.faults(interface_faults);                           \
  for (auto it : interface_faults)                        \
  {                                                       \
    param##_interface::Fault fault;                       \
    fault.timestamp.sec = it.timestamp().sec();           \
    fault.timestamp.nsec = it.timestamp().nsec();         \
    fault.code = it.code();                               \
    fault.reason = it.reason();                           \
    param##_faults.emplace_back(fault);                   \
  }                                                       \
  obj.app_id = msg.app_id();                              \
  obj.is_active = msg.is_active();                        \
  obj.faults = param##_faults;

// ros2
#define FAULTS_PARSER_2(param, obj)                          \
  obj.version = msg.version();                               \
  std::vector<param##_interface::msg::Fault> param##_faults; \
  std::vector<athena::interface::Fault> interface_faults;    \
  msg.faults(interface_faults);                              \
  for (auto it : interface_faults)                           \
  {                                                          \
    param##_interface::msg::Fault fault;                     \
    fault.timestamp.sec = it.timestamp().sec();              \
    fault.timestamp.nsec = it.timestamp().nsec();            \
    fault.code = it.code();                                  \
    fault.reason = it.reason();                              \
    param##_faults.emplace_back(fault);                      \
  }                                                          \
  obj.app_id = msg.app_id();                                 \
  obj.is_active = msg.is_active();                           \
  obj.faults = param##_faults;

#define EVENTS_PARSER(param, obj)                            \
  obj.version = msg.version();                               \
  std::vector<param##_interface::msg::Event> param##_events; \
  std::vector<athena::interface::Event> interface_events;    \
  msg.events(interface_events);                              \
  for (auto it : interface_events)                           \
  {                                                          \
    param##_interface::msg::Event event;                     \
    event.timestamp.sec = it.timestamp().sec();              \
    event.timestamp.nsec = it.timestamp().nsec();            \
    event.code = it.code();                                  \
    event.reason = it.reason();                              \
    param##_events.emplace_back(event);                      \
  }                                                          \
  obj.events = param##_events;

#define FAULTS_RECEIVE(obj)                          \
  athena::interface::Fault fault_temp;               \
  std::vector<athena::interface::Fault> faults_temp; \
  for (auto it : msg->faults)                        \
  {                                                  \
    athena::interface::Time t;                       \
    t.set_sec(it.timestamp.sec);                     \
    t.set_nsec(it.timestamp.nsec);                   \    
    fault_temp.set_timestamp(t);                     \    
    fault_temp.set_code(it.code);                    \
    fault_temp.set_reason(it.reason);                \
    faults_temp.push_back(fault_temp);               \
  }                                                  \
  obj.set_faults(&faults_temp);

#define EVENTS_RECEIVE(obj)                          \
  athena::interface::Event event_temp;               \
  std::vector<athena::interface::Event> events_temp; \
  for (auto it : msg->events)                        \
  {                                                  \
    athena::interface::Time t;                       \
    t.set_sec(it.timestamp.sec);                     \
    t.set_nsec(it.timestamp.nsec);                   \    
    event_temp.set_timestamp(t);                     \    
    event_temp.set_code(it.code);                    \
    event_temp.set_reason(it.reason);                \
    events_temp.push_back(event_temp);               \
  }                                                  \
  obj.set_events(&events_temp);


#define DDS_FAULTS_RECEIVE(obj)                      \
  athena::interface::Fault fault_temp;               \
  std::vector<athena::interface::Fault> faults_temp; \
  for (auto it : msg->faults())                      \
  {                                                  \
    athena::interface::Time t;                       \
    t.set_sec(it.timestamp().sec());                 \
    t.set_nsec(it.timestamp().nsec());               \    
    fault_temp.set_timestamp(t);                     \    
    fault_temp.set_code(it.code());                  \
    fault_temp.set_reason(it.reason());              \
    faults_temp.push_back(fault_temp);               \
  }                                                  \
  obj.set_faults(&faults_temp);

#define MSG_PARSER_POINT3D(param, object) \
  param.set_x(msg->param.x);              \
  param.set_y(msg->param.y);              \
  param.set_z(msg->param.z);              \
  object.set_##param(param);

#define MSG_PARSER_POINTLLH(param, object) \
  param.set_lon(msg->param.lon);           \
  param.set_lat(msg->param.lat);           \
  param.set_height(msg->param.height);     \
  object.set_##param(param);

#define MSG_PARSER_POINTENU(param, object) \
  param.set_x(msg->param.x);               \
  param.set_y(msg->param.y);               \
  param.set_z(msg->param.z);               \
  object.set_##param(param);

#define INTERFACE_HEADER_ASSIGN(param)         \
  static uint32_t param##_seq = 0;             \
  header.set_seq(param##_seq++);               \
  header.set_stamp(TimeTool::Now2TmeStruct()); \
  param.set_header(header);

#define DECLARE_SINGLETON(classname)                                      \
public:                                                                   \
  static classname *Instance(bool create_if_needed = true)                \
  {                                                                       \
    static classname *instance = nullptr;                                 \
    if (!instance && create_if_needed)                                    \
    {                                                                     \
      static std::once_flag flag;                                         \
      std::call_once(flag,                                                \
                     [&] { instance = new (std::nothrow) classname(); }); \
    }                                                                     \
    return instance;                                                      \
  }                                                                       \
                                                                          \
  static void CleanUp()                                                   \
  {                                                                       \
    auto instance = Instance(false);                                      \
    if (instance != nullptr)                                              \
    {                                                                     \
      CallShutdown(instance);                                             \
    }                                                                     \
  }                                                                       \
                                                                          \
private:                                                                  \
  classname();                                                            \
  DISALLOW_COPY_AND_ASSIGN(classname)
