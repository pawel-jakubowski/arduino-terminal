/*
 * Terminal.cpp
 *
 *  Created on: 18 sty 2015
 *      Author: Pawel Jakubowski
 */

#include "Terminal.h"

#include <iostream>
#include "Serial.h"

using namespace std;

Terminal::Terminal(string device) : input(0), output(0), serialDevice(device) {
}

Terminal::~Terminal() {
}

void* terminalOutput(void* runFlag) {
	bool *isRunning = reinterpret_cast<bool*>(runFlag);
	try {
		arduino::Serial USBReader("/dev/ttyUSB0");
		while (*isRunning)
		{
			cout << USBReader.read();
			cout.flush();
		}
	} catch (string& err) {
		cerr << "Error: " << err << endl;
	}
	cout << "End termialOutput()" << endl;
	return NULL;
}

void writeAction(arduino::Serial& USBWriter, std::string& userInput,
		bool* isRunning) {
	USBWriter.getId();
	getline(cin, userInput);
	if (userInput == "exit")
		*isRunning = false;
	else if (userInput.length() > 0)
		USBWriter.write(userInput.c_str());
}

void* terminalInput(void* runFlag) {
	bool *isRunning = reinterpret_cast<bool*>(runFlag);
	std::string userInput;
	try {
		arduino::Serial USBWriter("/dev/ttyUSB0");
		while(*isRunning)
			writeAction(USBWriter, userInput, isRunning);
	} catch (string& err) {
		cerr << "Error: " << err << endl;
	}
	cout << "End termialInput()" << endl;
	return NULL;
}

void Terminal::waitForThreads() {
	pthread_join(input, NULL);
	pthread_join(output, NULL);
}

void Terminal::run() {
	createTerminalThreads();
	waitForThreads();
}

void Terminal::createTerminalThreads() {
	bool appIsRunning = true;
	pthread_create(&input, NULL, terminalInput, &appIsRunning);
	pthread_create(&output, NULL, terminalOutput, &appIsRunning);
}

