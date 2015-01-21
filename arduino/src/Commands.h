/*
 * Commands.h
 *
 *  Created on: 18 sty 2015
 *      Author: Pawel Jakubowski
 */

#ifndef COMMANDS_H_
#define COMMANDS_H_

#include <stdint.h>

#define NUM_TRUE	1
#define NUM_FALSE	0
typedef uint8_t NumBool;

class Command {
	static const unsigned NameLength = 32;
public:
	Command();
	void init(const char* cmd, void (*func)());
	void exe() const;
	NumBool isNamed(const char* str) const;
	const char* getName();
private:
	char name[NameLength];
	void (*function)();
};

class Commands {
	static const unsigned CmdsNum = 3; // Change it if you add new command
public:
	void addCommand(const char* cmd, void (*func)());
	void exe(const char* str) const;
	Commands();
	Commands(int); // for test
	Command& operator[] (int ind) {
		return commands[ind];
	}
	unsigned& len() { return currCmdsNum; }
private:
	unsigned currCmdsNum;
	Command commands[CmdsNum];
};

#endif /* COMMANDS_H_ */
