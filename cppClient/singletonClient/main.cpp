#include "SingletonClient.h"

int main() {
	SingletonClient* sc = SingletonClient::getInstance();
	sc->connect();
	std::vector<float> m;
	for(int i = 0; i < 48; i++)
		m.push_back(float(i));
	sc->send(m);
	return 0;
}