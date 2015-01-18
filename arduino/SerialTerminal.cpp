/*
 * SerialTerminal.cpp
 *
 *  Created on: 16 sty 2015
 *      Author: Pawel Jakubowski
 */

#include <HardwareSerial.h>
#include "SerialTerminal.h"

SerialTerminal::SerialTerminal() :
		cmdFlag(0), readResult(-1) {
	memset(&cmd, '\0', sizeof cmd);
}

SerialTerminal::~SerialTerminal() {
}

void SerialTerminal::init() {
	Serial.begin(9600);
}

void SerialTerminal::readInput() {
	readResult = Serial.read();
	if (readResult >= 0)
		processReadedSign(static_cast<unsigned char>(readResult));
}

void SerialTerminal::executeCmd() {
	if (cmdFlag & newLine) {
		if (strcmp(cmd, "") == 0) {
			Serial.print("arduino@nano> ");
		} else if (strcmp(cmd, "test") == 0) {
			Serial.println("Test command :)");
		} else {
			Serial.print(cmd);
			Serial.println(": command not found");
		}

		memset(&cmd, '\0', sizeof cmd);
		cmdFlag = 0;
	}
}

void SerialTerminal::processReadedSign(char readedSign) {
	if (readedSign == '\n') {
		cmdFlag |= newLine;
	} else {
		char str[2] = { readedSign, '\0' };
		strcat(cmd, str);
	}
}

