#include "MqttClientEventHandler.h"
//#include "common/razerSDK/razer.h"

robot_dog::MqttClientEventHandler::MqttClientEventHandler(mqtt::async_client & cli)
	: _cli(cli)
{
}

void robot_dog::MqttClientEventHandler::setConnectCompletedEvent(ConnectCompletedEvent && event)
{
	m_completedEvent = event;
}

void robot_dog::MqttClientEventHandler::setMessageArrivedEvent(MessageArrivedEvent && event)
{
	m_messageArrivedEvent = event;
}

void robot_dog::MqttClientEventHandler::setConnectOptions(const mqtt::connect_options & connOpts)
{
	_connOpts = connOpts;
}

void robot_dog::MqttClientEventHandler::reconnect()
{
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	try
	{
		std::cout << ("mqtt start reconnect.") << std::endl ;
		_cli.connect(_connOpts, nullptr, *this);
	}
	catch (const std::exception &ex)
	{
		std::cout << ("mqtt reconnect failed.") << std::endl;
	}
}

void robot_dog::MqttClientEventHandler::connected(const std::string & cause)
{
	std::cout << ("mqtt[%s] connected.", cause.c_str()) << std::endl;
	if (m_completedEvent) m_completedEvent();
}

void robot_dog::MqttClientEventHandler::connection_lost(const std::string & cause)
{
	std::cout << "mqtt connection lost. : " << cause.c_str() << std::endl;
	reconnect();
}

void robot_dog::MqttClientEventHandler::message_arrived(mqtt::const_message_ptr msg)
{
	if (m_messageArrivedEvent) m_messageArrivedEvent(msg);
}

void robot_dog::MqttClientEventHandler::on_failure(const mqtt::token & asyncActionToken)
{
	std::cout << ("mqtt connection attempt failed.") << std::endl;
	reconnect();
}

void robot_dog::MqttClientEventHandler::on_success(const mqtt::token & asyncActionToken)
{
	std::cout << ("mqtt connection successful.") << std::endl;
}
