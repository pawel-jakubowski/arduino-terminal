#include <Arduino.h>
#include "SerialTerminal.h"

const int led = 13;
void (* volatile proc_ptr)() = 0;
SerialTerminal Terminal;

void setup() {
	Terminal.init();
}

void loop() {
	Terminal.readInput();
	Terminal.executeCmd();
	delay(5); // dirty hack to allow user to end process
	if (proc_ptr != 0)
		proc_ptr();
}
