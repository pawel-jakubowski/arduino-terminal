/*
 * Serial.cpp
 *
 *  Created on: 14 sty 2015
 *      Author: Pawel Jakubowski
 */

#include "Serial.h"

#include <iostream>
#include <cstring>

#include <stdio.h>      // standard input / output functions
#include <stdlib.h>
#include <string.h>     // string function definitions
#include <unistd.h>     // UNIX standard function definitions
#include <fcntl.h>      // File control definitions

#include <readline/readline.h>
#include <readline/history.h>

namespace arduino {

std::unique_ptr<MutexLock> Serial::blockade = std::unique_ptr<MutexLock>(
		new MutexLock());

Serial::Serial(std::string newName, int newBaudRate) :
		serialPortName(newName), fileDescriptor(0), baudRate(newBaudRate), portOpen(
				false) {
	if (!blockade)
		blockade.reset(new MutexLock());
	open();
	init();
}

Serial::~Serial() {
	close();
}

void Serial::readTerminalLine(std::string& str) {
	blockade->lock();
	str = ::readline(idPrompt.c_str());
	blockade->unlock();
	::add_history(str.c_str());
}

std::string Serial::getId() {
	write("");
	do {
		idPrompt = read();
	} while (idPrompt == "");
	return idPrompt;
}

void Serial::write(const char& sign) {
	write(&sign, sizeof(char));
}

void Serial::write(const char* string) {
	write(string, strlen(string));
}

void Serial::write(const char* string, size_t size) {
	blockade->lock();
	::write(fileDescriptor, string, size);
	::write(fileDescriptor, "\n", sizeof(char));
	blockade->unlock();
}

std::string Serial::read() {
	memset(&buf, '\0', sizeof buf);
	blockade->lock();
	int n = ::read(fileDescriptor, &buf, sizeof buf);
	blockade->unlock();

	if (n < 0)
		throw std::string("Serial::read() error [" + std::to_string(n) + "]");
	return std::string(buf);
}

void Serial::open() {
	/* Open File Descriptor */
	fileDescriptor = ::open(serialPortName.c_str(),
	O_RDWR | O_NOCTTY | O_NONBLOCK);

	/* Error Handling */
	if (fileDescriptor < 0)
		throw std::string(
				"Serial::open() error [" + std::to_string(fileDescriptor)
						+ "]");
}

void Serial::init() {
	/* *** Configure Port *** */
	memset(&oldSerialPortSettings, 0, sizeof oldSerialPortSettings);
	/* Save old tty parameters */

	int err = tcgetattr(fileDescriptor, &oldSerialPortSettings);
	if (err != 0)
		throw std::string("Serial::init() error [" + std::to_string(err) + "]");

	memset(&serialPortSettings, 0, sizeof serialPortSettings);

	// Enable the receiver (CREAD) and ignore modem control lines (CLOCAL)
	serialPortSettings.c_cflag |= CREAD | CLOCAL;

	// Set the VMIN and VTIME parameters to zero by default. VMIN is
	// the minimum number of characters for non-canonical read and
	// VTIME is the timeout in deciseconds for non-canonical
	// read. Setting both of these parameters to zero implies that a
	// read will return immediately only giving the currently
	// available characters.
	serialPortSettings.c_cc[VMIN] = 0;
	serialPortSettings.c_cc[VTIME] = 0;

	// Flush Port
	err = tcflush(fileDescriptor, TCIFLUSH);
	if (err != 0)
		throw std::string("Serial::init() error [" + std::to_string(err) + "]");

	// Apply settings to serial port
	err = tcsetattr(fileDescriptor, TCSANOW, &serialPortSettings);
	if (err != 0)
		throw std::string("Serial::init() error [" + std::to_string(err) + "]");

	portOpen = true;

	/* Set Baud Rate */
	cfsetospeed(&serialPortSettings, (speed_t) B9600);
	cfsetispeed(&serialPortSettings, (speed_t) B9600);
}

void Serial::close() {
	if (isOpened()) {
		// Restore the old settings of the port.
		tcsetattr(fileDescriptor, TCSANOW, &oldSerialPortSettings);
		::close(fileDescriptor);
		portOpen = false;
	}
}

bool Serial::isOpened() {
	return portOpen;
}

} /* namespace arduino */
