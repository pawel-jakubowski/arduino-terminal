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

void readAction(arduino::Serial& USBReader) {
	cout << USBReader.read();
	cout.flush();
}

void* terminalOutput(void* arguments) {
	threadArgs *args = reinterpret_cast<threadArgs*>(arguments);
	try {
		arduino::Serial USBReader(args->device);
		while (args->runFlag)
			readAction(USBReader);
	} catch (string& err) {
		cerr << "Error: " << err << endl;
	}
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

void* terminalInput(void* arguments) {
	threadArgs *args = reinterpret_cast<threadArgs*>(arguments);
	std::string userInput;
	try {
		arduino::Serial USBWriter(args->device);
		while(args->runFlag)
			writeAction(USBWriter, userInput, &args->runFlag);
	} catch (string& err) {
		cerr << "Error: " << err << endl;
	}
	return NULL;
}

Terminal::Terminal(string device) : input(0), output(0), serialDevice(device) {
}

Terminal::~Terminal() {
}

void Terminal::waitForThreads() {
	pthread_join(input, NULL);
	pthread_join(output, NULL);
}

void Terminal::run() {
	createTerminalThreads();
	waitForThreads();
}

void Terminal::initThreadArgs(threadArgs& args) {
	args.device = serialDevice;
	args.runFlag = true;
}

void Terminal::createTerminalThreads() {
	initThreadArgs(args);
	pthread_create(&input, NULL, terminalInput, &args);
	pthread_create(&output, NULL, terminalOutput, &args);
}

