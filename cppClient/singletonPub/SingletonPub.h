#ifndef _SINGLETON_PUB_H
#define _SINGLETON_PUB_H


#include "zmq.hpp"
#ifndef _WIN32
#include <unistd.h>
#else
#include <windows.h>
#define sleep(n)    Sleep(n)
#endif

class SingletonPub
{
	private:
	SingletonPub();
	~SingletonPub();

public:
	static SingletonPub* getInstance();

	void connect();

	void send(std::string topic, float msg);

private:
	//  Sends string as 0MQ string, as multipart non-terminal
	bool s_sendmore(std::string string);

	//  Convert string to 0MQ string and send to socket
	bool s_send(std::string string);

	bool s_send(const float & f);

private:
	static SingletonPub* m_instance;
	zmq::socket_t* m_socket;
	zmq::context_t* m_context;
};

#endif