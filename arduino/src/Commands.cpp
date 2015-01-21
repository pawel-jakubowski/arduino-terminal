/*
 * Commands.cpp
 *
 *  Created on: 18 sty 2015
 *      Author: Pawel Jakubowski
 */

#include "Commands.h"

#include <Arduino.h>
#include <commands/id.h>
#include <commands/test.h>

void Command::init(const char* cmd, void (*func)()) {
	if (strlen(cmd) >= NameLength)
		return;
	strcpy(name, cmd);
	function = func;
}

NumBool Command::isNamed(const char* str) const {
	return (strcmp(name, str) == 0) ? NUM_TRUE : NUM_FALSE;
}

const char* Command::getName() {
	return name;
}

Command::Command() :
		function(0) {
	memset(&name, '\0', sizeof name);
}

void Command::exe() const {
	function();
}

void Commands::exe(const char* str) const {
	for(unsigned i = 0; i < currCmdsNum; i++)
		if (commands[i].isNamed(str))
		{
			commands[i].exe();
			return;
		}
	Serial.print(str);
	Serial.println(": command not found");
}

void Commands::addCommand(const char* cmd, void (*func)()) {
	if (currCmdsNum >= CmdsNum)
		return;
	commands[currCmdsNum++].init(cmd, func);
}

Commands::Commands()
		: currCmdsNum(0) {
	addCommand("", commands::id);
	addCommand("test", commands::test);
}

Commands::Commands(int) : currCmdsNum(0) {
}
