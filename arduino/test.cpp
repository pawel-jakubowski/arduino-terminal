#include <Arduino.h>
#include "SerialTerminal.h"

const int led = 13;
SerialTerminal Terminal;

void setup() {
	Terminal.init();
	pinMode(led, OUTPUT);
}

void loop() {
	Terminal.readInput();
	Terminal.executeCmd();
}
