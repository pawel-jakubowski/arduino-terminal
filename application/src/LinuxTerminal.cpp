/*
 * Terminal.cpp
 *
 *  Created on: 18 sty 2015
 *      Author: Pawel Jakubowski
 */

#include "LinuxTerminal.h"

#include <iostream>
#include <stdio.h>      // standard input / output functions
#include <stdlib.h>
#include <string.h>     // string function definitions
#include <unistd.h>     // UNIX standard function definitions
#include <fcntl.h>      // File control definitions
#include <unistd.h>

#include "Serial.h"

using namespace std;

void readAction(arduino::Serial& USBReader, threadArgs* args) {
	std::string readResult(USBReader.read());
	cout << readResult << flush;
	if (!args->readEnd && readResult == "") {
		cout << "ReadEnds" << flush;
		args->readEnd = true;
	}
}

void* terminalOutput(void* arguments) {
	threadArgs *args = reinterpret_cast<threadArgs*>(arguments);
	while(!args->allowRead && args->runFlag) {}
	try {
		arduino::Serial USBReader(args->device);
		while (args->runFlag)
			readAction(USBReader, args);
	} catch (string& err) {
		cerr << "Error: " << err << endl;
	}
	return NULL;
}

void writeAction(arduino::Serial& USBWriter, std::string& userInput,
		threadArgs* args) {
	USBWriter.readTerminalLine(userInput);
	if (userInput == "exit")
		args->runFlag = false;
	else if (userInput.length() > 0) {
		USBWriter.write(userInput.c_str());
		args->readEnd = false;
		while (!args->readEnd) {}
//		usleep(7*10e3);
	}
}

void* terminalInput(void* arguments) {
	threadArgs *args = reinterpret_cast<threadArgs*>(arguments);
	std::string userInput;
	try {
		arduino::Serial USBWriter(args->device);
		USBWriter.getId();
		args->allowRead = true;
		while (args->runFlag)
			writeAction(USBWriter, userInput, args);
	} catch (string& err) {
		cerr << "Error: " << err << endl;
	}
	return NULL;
}

LinuxTerminal::LinuxTerminal(string device) :
		input(0), output(0), serialDevice(device) {
}

LinuxTerminal::~LinuxTerminal() {
}

void LinuxTerminal::waitForThreads() {
	pthread_join(input, NULL);
	pthread_join(output, NULL);
}

void LinuxTerminal::run() {
	createTerminalThreads();
	waitForThreads();
}

void LinuxTerminal::initThreadArgs(threadArgs& args) {
	args.device = serialDevice;
	args.runFlag = true;
	args.allowRead = false;
	args.readEnd = 0;
}

void LinuxTerminal::createTerminalThreads() {
	initThreadArgs(args);
	pthread_create(&input, NULL, terminalInput, &args);
	pthread_create(&output, NULL, terminalOutput, &args);
}

