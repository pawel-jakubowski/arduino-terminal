/*
 * Arduino.h
 *
 *  Created on: 21 sty 2015
 *      Author: Pawel Jakubowski
 */

#ifndef ARDUINO_H_
#define ARDUINO_H_

#include <iostream>
#include <cstring>

typedef unsigned char uint8_t;

class HardwareSerialMock {
public:
	void print(const char* str) { std::cout << str; }
	void println(const char* str) { std::cout << str << std::endl; }
};

HardwareSerialMock Serial;

#endif /* ARDUINO_H_ */
