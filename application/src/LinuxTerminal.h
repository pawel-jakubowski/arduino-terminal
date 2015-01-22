/*
 * Terminal.h
 *
 *  Created on: 18 sty 2015
 *      Author: Pawel Jakubowski
 */

#ifndef TERMINAL_H_
#define TERMINAL_H_

#include "TerminalInterface.h"

#include <string>
#include <pthread.h>

struct threadArgs {
	std::string device;
	bool runFlag;
	bool allowRead;
	int readEnd;
};

class LinuxTerminal : public TerminalInterface {
public:
	void run();
	LinuxTerminal(std::string device);
	virtual ~LinuxTerminal();
private:
	pthread_t input;
	pthread_t output;
	threadArgs args;
	std::string serialDevice;

	void createTerminalThreads();
	void waitForThreads();

	LinuxTerminal(LinuxTerminal&);
	LinuxTerminal& operator=(LinuxTerminal&);
	void initThreadArgs(threadArgs& args);
};

#endif /* TERMINAL_H_ */
