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

#include "LinuxTerminal.h"

int main(int argc, char *argv[]) {
	std::string serialPort = "/dev/ttyUSB0";

	if(argc == 2)
		serialPort = argv[1];

	TerminalInterface* arduino = new LinuxTerminal(serialPort);
	arduino->run();

	return 0;
}
