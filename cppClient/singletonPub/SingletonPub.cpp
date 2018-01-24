#include "SingletonPub.h"



SingletonPub::SingletonPub()
{
	m_context = new zmq::context_t(1);
	m_socket = new zmq::socket_t(*m_context, ZMQ_PUB);
}


SingletonPub::~SingletonPub()
{
}

SingletonPub* SingletonPub::getInstance()
{
	if (m_instance == NULL)
		m_instance = new SingletonPub;
	return m_instance;
}

bool SingletonPub::s_sendmore(std::string string)
{
	zmq::message_t message(string.size());
	memcpy(message.data(), string.data(), string.size());

	bool rc = m_socket->send(message, ZMQ_SNDMORE);
	return (rc);
}

bool SingletonPub::s_send(std::string string)
{
	zmq::message_t message(string.size());
	memcpy(message.data(), string.data(), string.size());

	bool rc = m_socket->send(message);
	return (rc);
}

bool SingletonPub::s_send(const float & f)
{
	zmq::message_t message(4);
	memcpy(message.data(), &f, 4);

	bool rc = m_socket->send(message);
	return (rc);
}

bool SingletonPub::s_send(float f[], int len)
{
	zmq::message_t message(4 * len);
	memcpy(message.data(), &f[0], 4 * len);

	bool rc = m_socket->send(message);
	return (rc);
}

void SingletonPub::connect()
{
	m_socket->bind("tcp://*:5563");
}

void SingletonPub::send(std::string topic, float msg)
{
	s_sendmore(topic);
	s_send(msg);
}

void SingletonPub::send(std::string topic, float msg[])
{
	s_sendmore(topic);
	s_send(msg, 4);
}

SingletonPub* SingletonPub::m_instance = NULL;
