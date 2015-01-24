/*
 * portStatus.cpp
 *
 *  Created on: 21 sty 2015
 *      Author: Pawel Jakubowski
 */

#include "portStatus.h"
#include <Arduino.h>

namespace commands {

void DigitalPortStatus() {
	Serial.print("Status\t");

	for (uint8_t i = 0; i < 8; i++)
		Serial.print((PIND & (1 << i)) ? '1' : '0');

	for (uint8_t i = 0; i < 6; i++)
		Serial.print((PINB & (1 << i)) ? '1' : '0');

	Serial.println("");
	Serial.print("Mode\t");

	for (uint8_t i = 0; i < 8; i++)
		Serial.print((DDRD & (1 << i)) ? 'O' : 'I');

	for (uint8_t i = 0; i < 6; i++)
		Serial.print((DDRB & (1 << i)) ? 'O' : 'I');

	Serial.println("");
}

void AnalogPortStatus() {
	for (uint8_t i = 0; i < 8; i++) {
		Serial.print(i);
		Serial.print(") ");
		Serial.print((DDRC & (1 << i)) ? "[OUT] " : "[IN ] ");
		Serial.println(analogRead(i));
	}
}

}
