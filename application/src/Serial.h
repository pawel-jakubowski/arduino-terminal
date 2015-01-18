/*
 * Serial.h
 *
 *  Created on: 14 sty 2015
 *      Author: Pawel Jakubowski
 */

#ifndef SERIAL_H_
#define SERIAL_H_

#include <memory>
#include <string>
#include <termios.h>    // POSIX terminal control definitions

#include "MutexLock.h"

namespace arduino {

class Serial {
	static std::unique_ptr<MutexLock> blockade;
public:
	std::string getId();
    void write(const char& sign);
    void write(const char* string);
    void write(const char* string, size_t size);
    std::string read();
    Serial(std::string newName, int newBaudRate = 9600);
    ~Serial();
private:
    std::string serialPortName;
    int fileDescriptor;
    int baudRate;
    char buf[255] = {'\0'};
    bool portOpen;
    struct termios serialPortSettings;
    struct termios oldSerialPortSettings;

    void open();
    void close();
	void init();
	bool isOpened();
};

} /* namespace arduino */

#endif /* SERIAL_H_ */
