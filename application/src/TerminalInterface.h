/*
 * TerminalInterface.h
 *
 *  Created on: 22 sty 2015
 *      Author: Pawel Jakubowski
 */

#ifndef TERMINALINTERFACE_H_
#define TERMINALINTERFACE_H_

#include <string>

class TerminalInterface {
public:
	virtual void run() = 0;
	virtual ~TerminalInterface() {}
};



#endif /* TERMINALINTERFACE_H_ */
