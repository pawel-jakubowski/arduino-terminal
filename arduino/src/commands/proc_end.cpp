/*
 * proc_end.cpp
 *
 *  Created on: 24 sty 2015
 *      Author: Pawel Jakubowski
 */

#include "proc_end.h"
#include <Arduino.h>

extern void (* volatile proc_ptr)();

namespace process {

void end() {
	::proc_ptr = 0;
	Serial.println("Process stopped!");
}

}


