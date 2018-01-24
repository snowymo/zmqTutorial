#include "SingletonPub.h"

int main() {
	SingletonPub::getInstance()->connect();
	while (1) {
		SingletonPub::getInstance()->send("A", float(rand() % 50) / 50.0f);
		SingletonPub::getInstance()->send("B", float(rand() % 50) / 50.0f + 2.0f);
	}
	return 0;
}