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

#define PINA	DUMMY_PORT
#define	PINB	DUMMY_PORT
#define PINC	DUMMY_PORT
#define PIND	DUMMY_PORT
#define PORTA	DUMMY_PORT
#define	PORTB	DUMMY_PORT
#define PORTC	DUMMY_PORT
#define PORTD	DUMMY_PORT
#define DDRA	DUMMY_PORT
#define	DDRB	DUMMY_PORT
#define DDRC	DUMMY_PORT
#define DDRD	DUMMY_PORT

typedef unsigned char uint8_t;
extern uint8_t DUMMY_PORT;

class HardwareSerialMock {
public:
	void print(uint8_t str) { std::cout << str; }
	void print(const char* str) { std::cout << str; }
	void println(const char* str) { std::cout << str << std::endl; }
	void println(int str) { std::cout << str << std::endl; }
};

extern HardwareSerialMock Serial;

uint8_t digitalRead(uint8_t);
int analogRead(uint8_t);

void itoa(int v, char *s, int r);

#endif /* ARDUINO_H_ */
