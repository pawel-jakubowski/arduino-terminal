/*
 * Arduino.cpp
 *
 *  Created on: 21 sty 2015
 *      Author: Pawel Jakubowski
 */

#include "Arduino.h"


uint8_t DUMMY_PORT = 0;
HardwareSerialMock Serial;

uint8_t digitalRead(uint8_t) { return 0x00; }
int analogRead(uint8_t) { return 0; }

void itoa(int v, char *s, int r){ sprintf(s, "%d", v); }
