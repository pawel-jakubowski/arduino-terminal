/*
 * Commands.cpp
 *
 *  Created on: 18 sty 2015
 *      Author: Pawel Jakubowski
 */

#include "Commands.h"
#include <Arduino.h>

void lorem() {
	Serial.println("Lorem ipsum dolor");
}

void Commands::exe(const char* str) const {
	commands[0].exe();
}

Commands::Commands() {
	commands[0].init("lorem",lorem);
}

