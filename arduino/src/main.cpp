#include <Arduino.h>
#include "SerialTerminal.h"

const int led = 13;
SerialTerminal Terminal;

void setup() {
	pinMode(led-2, OUTPUT);
	pinMode(led-1, OUTPUT);
	pinMode(led, OUTPUT);
	digitalWrite(led, HIGH);
	digitalWrite(led - 1, HIGH);
	Terminal.init();
}

void loop() {
	Terminal.readInput();
	Terminal.executeCmd();
}
