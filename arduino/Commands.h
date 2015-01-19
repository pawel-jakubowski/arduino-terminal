/*
 * Commands.h
 *
 *  Created on: 18 sty 2015
 *      Author: Pawel Jakubowski
 */

#ifndef COMMANDS_H_
#define COMMANDS_H_

#include <Arduino.h>

class Command {
	static const unsigned NameLength = 100;
public:
	Command() : function(0) {
		memset(&name, '\0', sizeof name);
	}
	void init(const char* cmd, void (*func)()) {
		if (strlen(cmd) >= NameLength)
			return;
		strncpy(name, cmd, strlen(cmd));
		function = func;
	}
	void exe() const {
		function();
	}
private:
	char name[NameLength];
	void (*function)();
};

class Commands {
	static const unsigned CmdsNum = 1;
public:
	void exe(const char* str) const;
	Commands();
private:
	Command commands[CmdsNum];
};

#endif /* COMMANDS_H_ */
