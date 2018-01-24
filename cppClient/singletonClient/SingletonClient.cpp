#include "SingletonClient.h"



SingletonClient::SingletonClient()
{
	m_context = new zmq::context_t(1);
	m_socket = new zmq::socket_t(*m_context, ZMQ_REQ);
}


SingletonClient::~SingletonClient()
{
	delete m_context;
	delete m_socket;
}

SingletonClient* SingletonClient::getInstance()
{
	if (m_insstance == NULL)
		m_insstance = new SingletonClient;
	return m_insstance;
}

void SingletonClient::connect()
{
	std::cout << "Connecting to hello world server" << std::endl;
		m_socket->connect("tcp://localhost:5555");
}

void SingletonClient::send(std::vector<float> m)
{
	zmq::message_t msg(sizeof(float) * m.size());
	//float* f = new float(m.size());
	//float* fp = f;
	//for (int i = 0; i < m.size(); i++) {
		memcpy(msg.data(), &m[0], sizeof(float) * m.size());
		//fp = fp + 4;
	//}
	//memcpy(msg.data(), f, sizeof(float) * 12 * m.size());
	m_socket->send(msg);
	//  Get the reply.
	zmq::message_t reply;
	m_socket->recv(&reply);
	std::cout << "Received"<< std::endl;

	//  Do 10 requests, waiting each time for a response
// 	for (int request_nbr = 0; request_nbr != 10; request_nbr++) {
// 		zmq::message_t request(5);
// 		memcpy(request.data(), "Hello", 5);
// 		std::cout << "Sending Hello " << request_nbr << "\t" << std::endl;
// 		m_socket->send(request);
// 
// 		//  Get the reply.
// 		zmq::message_t reply;
// 		m_socket->recv(&reply);
// 		std::cout << "Received World " << request_nbr << std::endl;
// 	}
}

SingletonClient* SingletonClient::m_insstance = NULL;
