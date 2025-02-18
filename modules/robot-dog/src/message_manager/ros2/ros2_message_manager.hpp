/**
 * @file    ros_2_message_manager.hpp
 * @author  hyzx
 * @date    2022-05-06
 * @version 1.0.0
 * @par     Copyright(c)
 * @license GNU General Public License (GPL)
 */

#include "ros2_message_manager.h"
#include "modules/common/macros/macros.h"
#include "modules/common/logging/logging.h"

#if ROS2_ENABLE
/**
 * @namespace athena::function
 * @brief athena::function
 */

namespace athena
{
  namespace function
  {
    using namespace athena::common;

    using ::ros2_interface::msg::Chassis;
    using ::ros2_interface::msg::Events;
    using ::ros2_interface::msg::ObuCmdMsg;

    template <typename T>
    Ros2MessageManager<T>::Ros2MessageManager() : Node{"emergency_stop_node"} {}
    template <typename T>
    void Ros2MessageManager<T>::Init(T *t)
    {
      is_init_ = false;
      is_active_ = false;
      instance_ = t;
      action_mode_ = MessageActionMode::DO_NOTHING;

      using rclcpp::QoS;
      using SubAllocT =
          rclcpp::SubscriptionOptionsWithAllocator<std::allocator<void>>;
      using PubAllocT = rclcpp::PublisherOptionsWithAllocator<std::allocator<void>>;

      obu_cmd_msg_output_pub_ = create_publisher<::ros2_interface::msg::ObuCmdMsg>(
          "/function/emergency_stop/ObuCmdMsg", QoS{10}, PubAllocT{});

      events_output_pub_ = create_publisher<::ros2_interface::msg::Events>(
          "/function/emergency_stop/Events", QoS{10}, PubAllocT{});

      obu_cmd_msg_input_sub_ = create_subscription<ObuCmdMsg>(
          "/state_manager/ObuCmdMsg", QoS{30},
          [this](const ros2_interface::msg::ObuCmdMsg::SharedPtr msg)
          {
            Ros2MessageManager::HandleObuCmdMsgMessage(msg);
          },
          SubAllocT{});

      // 线程执行开始
      handle_message_thread_.reset(new std::thread([this]
                                                   { Run(); }));
      if (handle_message_thread_ == nullptr)
      {
        AERROR << "Unable to create handle_message_thread thread.";
        return;
      }
      handle_avtive_thread_.reset(new std::thread([this]
                                                  { ActivateMode(); }));
      if (handle_avtive_thread_ == nullptr)
      {
        AERROR << "Unable to create handle_avtive_thread_ thread.";
        return;
      }
      is_init_ = true;
    }

    template <typename T>
    bool Ros2MessageManager<T>::Activate()
    {
      std::unique_lock<std::mutex> lock(mode_mutex_);
      if (is_active_ == true)
      {
        std::cout << "already start" << std::endl;
        action_mode_ = MessageActionMode::DO_NOTHING;
        return false;
      }
      else
      {
        action_mode_ = MessageActionMode::TO_ACTIVATE;
      }
      return true;
    }

    template <typename T>
    void Ros2MessageManager<T>::TaskStart()
    {
      std::lock_guard<std::mutex> lock(mutex_);
      if (is_active_ == true)
      {
        return;
      }
      using rclcpp::QoS;
      using SubAllocT =
          rclcpp::SubscriptionOptionsWithAllocator<std::allocator<void>>;

      std::cout << "ros2 activate" << std::endl;

      std::cout << "ros2 activate" << std::endl;
      chassis_sub_ = create_subscription<Chassis>(
          "/drivers/canbus/Chassis", QoS{30},
          [this](const ros2_interface::msg::Chassis::SharedPtr msg)
          {
            Ros2MessageManager::HandleChassisMessage(msg);
          },
          SubAllocT{});

      events_sub_ = create_subscription<Events>(
          "/state_manager/Events", QoS{30},
          [this](const ros2_interface::msg::Events::SharedPtr msg)
          {
            Ros2MessageManager::HandleEventsMessage(msg);
          },
          SubAllocT{});

      action_mode_ = MessageActionMode::DO_NOTHING;
      is_active_ = true;
      return;
    }

    template <typename T>
    bool Ros2MessageManager<T>::DeActivate()
    {
      std::unique_lock<std::mutex> lock(mode_mutex_);
      if (is_active_ == false)
      {
        std::cout << "already stop" << std::endl;
        action_mode_ = MessageActionMode::DO_NOTHING;
        return false;
      }
      else
      {
        action_mode_ = MessageActionMode::TO_DEACTIVATE;
      }
      return true;
    }

    template <typename T>
    void Ros2MessageManager<T>::TaskStop()
    {
      if (is_active_ == false)
      {
        return;
      }

      chassis_sub_ = nullptr;
      events_sub_ = nullptr;
      obu_cmd_msg_input_sub_ = nullptr;
      action_mode_ = MessageActionMode::DO_NOTHING;
      is_active_ = false;
      return;
    }

    template <typename T>
    void Ros2MessageManager<T>::PublishObuCmdMsgOutput(
        athena::interface::ObuCmdMsg msg)
    {
      if (is_active_ == false)
        return;
      ::ros2_interface::msg::ObuCmdMsg obu_cmd_msg;
      MESSAGE_HEADER_ASSIGN(ros2_interface::msg, obu_cmd_msg)
      obu_cmd_msg.id = msg.id();
      obu_cmd_msg.name = msg.name();
      std::vector<ros2_interface::msg::ObuCmd> ros_obu_cmd_list;
      std::vector<athena::interface::ObuCmd> athena_obu_cmd_list;
      msg.obu_cmd_list(athena_obu_cmd_list);
      for (auto it_obu_cmd_list : athena_obu_cmd_list)
      {
        ::ros2_interface::msg::ObuCmd obu_cmd_msg_obu_cmd;
        obu_cmd_msg_obu_cmd.code = it_obu_cmd_list.code();
        obu_cmd_msg_obu_cmd.val = it_obu_cmd_list.val();
        ros_obu_cmd_list.emplace_back(obu_cmd_msg_obu_cmd);
      }
      obu_cmd_msg.obu_cmd_list = ros_obu_cmd_list;

      obu_cmd_msg_output_pub_->publish(obu_cmd_msg);
    }

    template <typename T>
    void Ros2MessageManager<T>::PublishEventsOutput(athena::interface::Events msg)
    {
      if (is_active_ == false)
        return;
      ::ros2_interface::msg::Events events;
      MESSAGE_HEADER_ASSIGN(ros2_interface::msg, events)
      events.version = msg.version();
      std::vector<ros2_interface::msg::Event> ros_events_vector;
      std::vector<athena::interface::Event> athena_events_vector;
      msg.events(athena_events_vector);
      for (auto it_events_vector : athena_events_vector)
      {
        ::ros2_interface::msg::Event events_event;
        ::ros2_interface::msg::Time events_event_timestamp;
        events_event_timestamp.sec = it_events_vector.timestamp().sec();
        events_event_timestamp.nsec = it_events_vector.timestamp().nsec();
        events_event.timestamp = events_event_timestamp;
        events_event.code = it_events_vector.code();
        events_event.reason = it_events_vector.reason();
        ros_events_vector.emplace_back(events_event);
      }
      events.events = ros_events_vector;

      events_output_pub_->publish(events);
    }

    template <typename T>
    void Ros2MessageManager<T>::HandleChassisMessage(
        const ros2_interface::msg::Chassis::SharedPtr msg_obj_ptr)
    {
      if (is_active_ == false)
        return;
      std::shared_ptr<ros2_interface::msg::Chassis> msg =
          std::const_pointer_cast<ros2_interface::msg::Chassis>(msg_obj_ptr);

      athena::interface::Chassis chassis;
      MESSAGE_HEADER_PARSER(chassis)
      chassis.set_moving_status((athena::common::MovingStatus)msg->moving_status);
      chassis.set_driving_mode((athena::common::DrivingMode)msg->driving_mode);
      chassis.set_steer_driving_mode(
          (athena::common::DrivingMode)msg->steer_driving_mode);
      chassis.set_steering_status(
          (athena::common::ControlStatus)msg->steering_status);
      chassis.set_front_steering_value(msg->front_steering_value);
      chassis.set_rear_steering_value(msg->rear_steering_value);
      chassis.set_steering_torque_nm(msg->steering_torque_nm);
      chassis.set_front_steering_rate_dps(msg->front_steering_rate_dps);
      chassis.set_rear_steering_rate_dps(msg->rear_steering_rate_dps);
      chassis.set_accel_driving_mode(
          (athena::common::DrivingMode)msg->accel_driving_mode);
      chassis.set_accel_status((athena::common::ControlStatus)msg->accel_status);
      chassis.set_accel_value(msg->accel_value);
      chassis.set_brake_driving_mode(
          (athena::common::DrivingMode)msg->brake_driving_mode);
      chassis.set_brake_status((athena::common::ControlStatus)msg->brake_status);
      chassis.set_brake_value(msg->brake_value);
      chassis.set_backup_brake_driving_mode(
          (athena::common::DrivingMode)msg->backup_brake_driving_mode);
      chassis.set_backup_brake_status(
          (athena::common::ControlStatus)msg->backup_brake_status);
      chassis.set_backup_brake_value(msg->backup_brake_value);
      chassis.set_epb_driving_mode(
          (athena::common::DrivingMode)msg->epb_driving_mode);
      chassis.set_epb_status((athena::common::ControlStatus)msg->epb_status);
      chassis.set_epb_level((athena::common::EPBLevel)msg->epb_level);
      chassis.set_engine_status((athena::common::EngineStauts)msg->engine_status);
      chassis.set_engine_rpm(msg->engine_rpm);
      chassis.set_engine_torque(msg->engine_torque);
      chassis.set_speed_mps(msg->speed_mps);
      chassis.set_odometer_m(msg->odometer_m);
      chassis.set_fuel_range_m(msg->fuel_range_m);
      chassis.set_gear_driving_mode(
          (athena::common::DrivingMode)msg->gear_driving_mode);
      chassis.set_gear_status((athena::common::ControlStatus)msg->gear_status);
      chassis.set_gear_location((athena::common::GearPosition)msg->gear_location);
      chassis.set_driver_seat_belt(
          (athena::common::SwitchStatus)msg->driver_seat_belt);
      chassis.set_high_beam_status(
          (athena::common::SwitchStatus)msg->high_beam_status);
      chassis.set_low_beam_status(
          (athena::common::SwitchStatus)msg->low_beam_status);
      chassis.set_horn_status((athena::common::SwitchStatus)msg->horn_status);
      chassis.set_turn_lamp_status(
          (athena::common::TurnSignal)msg->turn_lamp_status);
      chassis.set_front_wiper_status(
          (athena::common::SwitchStatus)msg->front_wiper_status);
      chassis.set_rear_wiper_status(
          (athena::common::SwitchStatus)msg->rear_wiper_status);
      chassis.set_position_lamp_status(
          (athena::common::SwitchStatus)msg->position_lamp_status);
      chassis.set_front_fog_lamp_status(
          (athena::common::SwitchStatus)msg->front_fog_lamp_status);
      chassis.set_rear_fog_lamp_status(
          (athena::common::SwitchStatus)msg->rear_fog_lamp_status);
      chassis.set_brake_lamp_status(
          (athena::common::SwitchStatus)msg->brake_lamp_status);
      chassis.set_alarm_lamp_status(
          (athena::common::SwitchStatus)msg->alarm_lamp_status);
      chassis.set_lf_door_status((athena::common::DoorStatus)msg->lf_door_status);
      chassis.set_rf_door_status((athena::common::DoorStatus)msg->rf_door_status);
      chassis.set_lr_door_status((athena::common::DoorStatus)msg->lr_door_status);
      chassis.set_rr_door_status((athena::common::DoorStatus)msg->rr_door_status);
      chassis.set_rearview_mirror_status(
          (athena::common::FoldUnfoldStatus)msg->rearview_mirror_status);
      chassis.set_trunk_status((athena::common::DoorStatus)msg->trunk_status);
      chassis.set_engine_bay_door_status(
          (athena::common::DoorStatus)msg->engine_bay_door_status);
      chassis.set_wheel_direction_rr(
          (athena::common::WheelSpeedType)msg->wheel_direction_rr);
      chassis.set_wheel_spd_rr(msg->wheel_spd_rr);
      chassis.set_wheel_direction_rl(
          (athena::common::WheelSpeedType)msg->wheel_direction_rl);
      chassis.set_wheel_spd_rl(msg->wheel_spd_rl);
      chassis.set_wheel_direction_fr(
          (athena::common::WheelSpeedType)msg->wheel_direction_fr);
      chassis.set_wheel_spd_fr(msg->wheel_spd_fr);
      chassis.set_wheel_direction_fl(
          (athena::common::WheelSpeedType)msg->wheel_direction_fl);
      chassis.set_wheel_spd_fl(msg->wheel_spd_fl);
      chassis.set_is_tire_pressure_ok(
          (athena::common::FailureStatus)msg->is_tire_pressure_ok);
      chassis.set_is_tire_pressure_lf_valid(
          (athena::common::IsValid)msg->is_tire_pressure_lf_valid);
      chassis.set_tire_pressure_lf(msg->tire_pressure_lf);
      chassis.set_is_tire_pressure_rf_valid(
          (athena::common::IsValid)msg->is_tire_pressure_rf_valid);
      chassis.set_tire_pressure_rf(msg->tire_pressure_rf);
      chassis.set_is_tire_pressure_lr_valid(
          (athena::common::IsValid)msg->is_tire_pressure_lr_valid);
      chassis.set_tire_pressure_lr(msg->tire_pressure_lr);
      chassis.set_is_tire_pressure_rr_valid(
          (athena::common::IsValid)msg->is_tire_pressure_rr_valid);
      chassis.set_tire_pressure_rr(msg->tire_pressure_rr);
      chassis.set_battery_power_percentage(msg->battery_power_percentage);
      chassis.set_air_bag_status(
          (athena::common::FailureStatus)msg->air_bag_status);
      chassis.set_charging_gun_status(
          (athena::common::PlugStatus)msg->charging_gun_status);
      chassis.set_vehicle_power_status(
          (athena::common::FailureStatus)msg->vehicle_power_status);
      std::vector<athena::interface::Chassis::ErrorCode> chassis_error_code;
      for (auto it_chassis_error_code : msg->chassis_error_code)
      {
        athena::interface::Chassis::ErrorCode error_code;
        error_code = (athena::interface::Chassis::ErrorCode)it_chassis_error_code;
        chassis_error_code.emplace_back(error_code);
      }
      chassis.set_chassis_error_code(&chassis_error_code);

      instance_->HandleChassis(chassis);
    }

    template <typename T>
    void Ros2MessageManager<T>::HandleEventsMessage(
        const ros2_interface::msg::Events::SharedPtr msg_obj_ptr)
    {
      if (is_active_ == false)
        return;
      std::shared_ptr<ros2_interface::msg::Events> msg =
          std::const_pointer_cast<ros2_interface::msg::Events>(msg_obj_ptr);

      athena::interface::Events events;

      instance_->HandleEvents(events);
    }

    template <typename T>
    void Ros2MessageManager<T>::HandleObuCmdMsgMessage(
        const ros2_interface::msg::ObuCmdMsg::SharedPtr msg_obj_ptr)
    {
      if (is_init_ == false)
        return;
      std::shared_ptr<ros2_interface::msg::ObuCmdMsg> msg =
          std::const_pointer_cast<ros2_interface::msg::ObuCmdMsg>(msg_obj_ptr);

      athena::interface::ObuCmdMsg obu_cmd_msg;
      MESSAGE_HEADER_PARSER(obu_cmd_msg)
      obu_cmd_msg.set_id(msg->id);
      obu_cmd_msg.set_name(msg->name);
      std::vector<athena::interface::ObuCmd> obu_cmd_list;
      for (auto it_obu_cmd_list : msg->obu_cmd_list)
      {
        athena::interface::ObuCmd obu_cmd_msg_obu_cmd;
        obu_cmd_msg_obu_cmd.set_code(it_obu_cmd_list.code);
        obu_cmd_msg_obu_cmd.set_val(it_obu_cmd_list.val);
        obu_cmd_list.emplace_back(obu_cmd_msg_obu_cmd);
      }
      obu_cmd_msg.set_obu_cmd_list(&obu_cmd_list);

      instance_->HandleObuCmdMsgInput(obu_cmd_msg);
    }

    template <typename T>
    void Ros2MessageManager<T>::Run()
    {
      rclcpp::spin(shared_from_this());
      rclcpp::shutdown();
      exit(0);
    }

    template <typename T>
    void Ros2MessageManager<T>::ActivateMode()
    {
      while (true)
      {
        std::unique_lock<std::mutex> lock(mode_mutex_);
        switch (action_mode_)
        {
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

    template <typename T>
    void Ros2MessageManager<T>::Stop()
    {
      if (handle_message_thread_ != nullptr && handle_message_thread_->joinable())
      {
        handle_message_thread_->join();
        handle_message_thread_.reset();
        AINFO << "handle_message_thread stopped [ok].";
      }
    }
  } // namespace function
} // namespace athena
#endif
