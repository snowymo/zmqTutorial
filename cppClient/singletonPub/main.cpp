#include "SingletonPub.h"

int main() {
	SingletonPub::getInstance()->connect();
	float test[4];
	
	while (1) {
		SingletonPub::getInstance()->send("A", float(rand() % 50) / 50.0f);
		for (int i = 0; i < 4; i++) {
			test[i] = float(rand() % 50) / 50.0f + 2.0f;
		}
		SingletonPub::getInstance()->send("m04", test);
	}
	return 0;
}