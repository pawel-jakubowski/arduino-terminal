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

#include "Terminal.h"

int main(int argc, char *argv[]) {
	Terminal arduino("/dev/ttyUSB0");
	arduino.run();

	return 0;
}
