/*
 * proc_dummy.cpp
 *
 *  Created on: 24 sty 2015
 *      Author: Pawel Jakubowski
 */

#include "proc_dummy.h"
#include <Arduino.h>

extern void (* volatile proc_ptr)();

namespace process {

void startDummy() {
	::proc_ptr = dummy;
}

void dummy() {
	Serial.println("\rIt's dummy process!");
}

}


