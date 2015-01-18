//============================================================================
// Name        : ArduinoTerminal.cpp
// Author      : Pawel Jakubowski
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <sstream>
#include <pthread.h>

#include "Serial.h"

using namespace std;

void* termialOutput(void*) {
	try {
		arduino::Serial USBReader("/dev/ttyUSB0");
		while (true)
		{
			cout << USBReader.read();
			cout.flush();
		}
	} catch (string& err) {
		cerr << "Error: " << err << endl;
	}
	return NULL;
}

void* termialInput(void*) {
	try {
		arduino::Serial USBWriter("/dev/ttyUSB0");

		USBWriter.getId();
		std::string userInput;
		while(true) {
			getline(cin, userInput);
			if (userInput.length() > 0)
				USBWriter.write(userInput.c_str());
			USBWriter.getId();
		}
	} catch (string& err) {
		cerr << "Error: " << err << endl;
	}
	return NULL;
}

int main(int argc, char *argv[]) {
	pthread_t terminalThreads[2];

	pthread_create(&terminalThreads[0], NULL, termialInput, NULL);
	pthread_create(&terminalThreads[1], NULL, termialOutput, NULL);

	// TODO save thread exit on error or "exit" cmd
	pthread_join(terminalThreads[0], NULL);
	pthread_join(terminalThreads[1], NULL);

	return 0;
}
