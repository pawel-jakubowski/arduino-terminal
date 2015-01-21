/*
 * TestStream.h
 *
 *  Created on: 21 sty 2015
 *      Author: Pawel Jakubowski
 */

#ifndef TESTSTREAM_H_
#define TESTSTREAM_H_

#include "gtest/gtest.h"

class TestStream: public ::testing::Test {
protected:
	std::stringstream buffer;
	const std::streambuf *sbuf = std::cout.rdbuf();

	TestStream() {
		std::cout.rdbuf(buffer.rdbuf());
	}
	~TestStream() {
		std::cout.rdbuf(const_cast<std::basic_streambuf<char>*>(sbuf));
	}
};

#endif /* TESTSTREAM_H_ */
