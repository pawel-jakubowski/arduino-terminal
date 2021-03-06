/*
 * SerialTerminal.h
 *
 *  Created on: 16 sty 2015
 *      Author: Pawel Jakubowski
 */

#ifndef SERIALTERMINAL_H_
#define SERIALTERMINAL_H_

#include "Commands.h"

class SerialTerminal {
	static const unsigned CmdSize = 255;
	static const uint8_t newLine = 0x01;
public:
	void init();
	void readInput();
	void executeCmd();
	SerialTerminal();
	~SerialTerminal();

private:
	Commands commands;
	char cmd[CmdSize];
	uint8_t cmdFlag;
	int readResult;

	void processReadedSign();
};

#endif /* SERIALTERMINAL_H_ */
