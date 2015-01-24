/*
 * test.cpp
 *
 *  Created on: 21 sty 2015
 *      Author: Pawel Jakubowski
 */

#include "test.h"
#include <Arduino.h>

namespace commands {

void test() {
	Serial.println("Test command - if you see this it's work :)");
}

}
