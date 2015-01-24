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
#include <commands/portStatus.h>
#include <commands/proc_end.h>
#include <commands/proc_dummy.h>

#define END_OF_TEXT (char)0x03 // ASCII sign to know that command is over

/* ~~~~~~~~~~~~~ COMMAND ~~~~~~~~~~~~~~ */

void Command::init(const char* cmd, void (*func)()) {
	if (strlen(cmd) >= NameLength)
		return;
	strcpy(name, cmd);
	function = func;
}

NumBool Command::isNamed(const char* str) const {
	return (strcmp(name, str) == 0) ? NUM_TRUE : NUM_FALSE;
}

const char* Command::getName() const {
	return name;
}

Command::Command() :
		function(0) {
	memset(&name, '\0', sizeof name);
}

void Command::exe() const {
	function();
	Serial.print(END_OF_TEXT);
}

/* ~~~~~~~~~~~~~ COMMANDS ~~~~~~~~~~~~~ */

void Commands::printCommands() const {
	for(unsigned i = 1; i < currCmdsNum; i++)
		Serial.println(commands[i].getName());
	Serial.print(END_OF_TEXT);
}

void Commands::cmdNotFound(const char* str) const {
	Serial.print(str);
	Serial.println(": command not found");
	Serial.print(END_OF_TEXT);
}

void Commands::exe(const char* str) const {
	if (strcmp("help",str) == 0){
		printCommands();
		return;
	}
	for(unsigned i = 0; i < currCmdsNum; i++)
		if (commands[i].isNamed(str))
		{
			commands[i].exe();
			return;
		}
	cmdNotFound(str);
}

void Commands::addCommand(const char* cmd, void (*func)()) {
	if (currCmdsNum >= CmdsNum)
		return;
	commands[currCmdsNum++].init(cmd, func);
}

Commands::Commands()
		: currCmdsNum(0) {
	addCommand("", commands::id);
	addCommand("aport", commands::AnalogPortStatus);
	addCommand("dport", commands::DigitalPortStatus);
	addCommand("q", process::end);
	addCommand("start dummy", process::startDummy);
	addCommand("test", commands::test);
}

Commands::Commands(int) : currCmdsNum(0) {
}

