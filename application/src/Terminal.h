/*
 * Terminal.h
 *
 *  Created on: 18 sty 2015
 *      Author: Pawel Jakubowski
 */

#ifndef TERMINAL_H_
#define TERMINAL_H_

#include <string>
#include <pthread.h>

struct threadArgs {
	std::string device;
	bool runFlag;
};

class Terminal {
public:
	void run();
	Terminal(std::string device);
	virtual ~Terminal();
private:
	pthread_t input;
	pthread_t output;
	threadArgs args;
	std::string serialDevice;

	void createTerminalThreads();
	void waitForThreads();

	Terminal(Terminal&);
	Terminal& operator=(Terminal&);
	void initThreadArgs(threadArgs& args);
};

#endif /* TERMINAL_H_ */
