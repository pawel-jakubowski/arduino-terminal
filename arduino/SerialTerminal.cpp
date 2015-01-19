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
		} else if (strcmp(cmd, "test1") == 0) {
			Serial.println("Test1 command :)");
		} else if (strcmp(cmd, "test2") == 0) {
			Serial.println("Test2 command :)");
		} else if (strcmp(cmd, "test3") == 0) {
			Serial.println("Test3 command :)");
		} else if (strcmp(cmd, "test4") == 0) {
			Serial.println("Test4 command :)");
		} else if (strcmp(cmd, "test5") == 0) {
			Serial.println("Test5 command :)");
		} else if (strcmp(cmd, "test6") == 0) {
			Serial.println("Test6 command :)");
		} else if (strcmp(cmd, "test7") == 0) {
			Serial.println("Test7 command :)");
		} else if (strcmp(cmd, "test8") == 0) {
			Serial.println("Test8 command :)");
		} else if (strcmp(cmd, "test9") == 0) {
			Serial.println("Test9 command :)");
		} else if (strcmp(cmd, "test10") == 0) {
			Serial.println("Test10 command :)");
		} else if (strcmp(cmd, "lorem") == 0) {
			commands.exe("");
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

