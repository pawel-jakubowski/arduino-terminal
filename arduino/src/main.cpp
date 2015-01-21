#include <Arduino.h>
#include "SerialTerminal.h"

const int led = 13;
SerialTerminal Terminal;

void setup() {
	Terminal.init();
}

void loop() {
	Terminal.readInput();
	Terminal.executeCmd();
}
