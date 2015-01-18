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

class Terminal {
public:
	void run();
	Terminal(std::string device);
	virtual ~Terminal();
private:
	pthread_t input;
	pthread_t output;
	std::string serialDevice;

	void createTerminalThreads();
	void waitForThreads();

	Terminal(Terminal&);
	Terminal& operator=(Terminal&);
};

#endif /* TERMINAL_H_ */
