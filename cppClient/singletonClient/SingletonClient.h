#pragma once

#include <zmq.hpp>
#include <iostream>
#include <vector>

class SingletonClient
{
public:
	SingletonClient();
	~SingletonClient();


public:
	static SingletonClient* getInstance();
	void connect();
	void send(std::vector<float> m);
	//void send(std::vector<float> m);

private:
	static SingletonClient* m_insstance;

	 	 zmq::context_t* m_context;
	 	 zmq::socket_t* m_socket;
};

