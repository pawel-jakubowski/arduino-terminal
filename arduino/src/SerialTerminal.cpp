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
	if (readResult >= 0){
		processReadedSign();
	}
}

void SerialTerminal::executeCmd() {
	if (cmdFlag & newLine) {
		commands.exe(cmd);
		memset(&cmd, '\0', sizeof cmd);
		cmdFlag = 0;
	}
}

void SerialTerminal::processReadedSign() {
	if ((unsigned char)readResult == '\n') {
		cmdFlag |= newLine;
	} else {
		char str[2] = { (unsigned char)readResult, '\0' };
		strcat(cmd, str);
	}
}

