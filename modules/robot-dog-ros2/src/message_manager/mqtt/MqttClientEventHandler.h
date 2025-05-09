#ifndef __MQTT_EVENT_PROCESS_H__
#define __MQTT_EVENT_PROCESS_H__
#if MQTT_ENABLE
#include <functional>
#include <mqtt/async_client.h>

namespace robot_dog {
	class MqttClientEventHandler : public virtual mqtt::callback
						  , public virtual mqtt::iaction_listener
	{
	public:
		using ConnectCompletedEvent = std::function<void(void)>;
		using MessageArrivedEvent = std::function<void(mqtt::const_message_ptr msg)>;
	public:
		MqttClientEventHandler(mqtt::async_client &cli);

		void setConnectCompletedEvent(ConnectCompletedEvent &&event);
		void setMessageArrivedEvent(MessageArrivedEvent &&event);
		void setConnectOptions(const mqtt::connect_options& connOpts);
	protected:
		void reconnect();
		virtual void connected(const std::string& cause) override;
		virtual void connection_lost(const std::string& cause) override;
		virtual void message_arrived(mqtt::const_message_ptr msg) override;
		virtual void on_failure(const mqtt::token& asyncActionToken) override;
		virtual void on_success(const mqtt::token& asyncActionToken) override;
	private:
		mqtt::async_client&		_cli;
		mqtt::connect_options	_connOpts;

		ConnectCompletedEvent	m_completedEvent;
		MessageArrivedEvent		m_messageArrivedEvent;
	};
}

#endif  // MQTT_ENABLE
#endif // !__MQTT_EVENT_PROCESS_H__