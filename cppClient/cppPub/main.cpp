#include "zmq.hpp"
#ifndef _WIN32
#include <unistd.h>
#else
#include <windows.h>
#define sleep(n)    Sleep(n)
#endif

//  Sends string as 0MQ string, as multipart non-terminal
static bool
s_sendmore(zmq::socket_t & socket, const std::string & string) {

	zmq::message_t message(string.size());
	memcpy(message.data(), string.data(), string.size());

	bool rc = socket.send(message, ZMQ_SNDMORE);
	return (rc);
}

//  Convert string to 0MQ string and send to socket
static bool
s_send(zmq::socket_t & socket, const std::string & string) {

	zmq::message_t message(string.size());
	memcpy(message.data(), string.data(), string.size());

	bool rc = socket.send(message);
	return (rc);
}

static bool
s_send(zmq::socket_t & socket, const float & f) {

	zmq::message_t message(4);
	memcpy(message.data(), &f, 4);

	bool rc = socket.send(message);
	return (rc);
}

int main() {
	//  Prepare our context and publisher
	zmq::context_t context(1);
	zmq::socket_t publisher(context, ZMQ_PUB);
	publisher.bind("tcp://*:5563");

	while (1) {
		//  Write two messages, each with an envelope and content
		s_sendmore(publisher, "A");
		s_send(publisher, float(rand()%50)/50.0f);
		s_sendmore(publisher, "B");
		s_send(publisher, float(rand() % 50) / 50.0f + 2.0f);
		sleep(1);
	}
	return 0;
}