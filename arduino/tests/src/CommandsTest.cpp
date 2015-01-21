/*
 * CommandsTest.cpp
 *
 *  Created on: 21 sty 2015
 *      Author: Pawel Jakubowski
 */

#include "Commands.h"
#include "gtest/gtest.h"

#include <string>
#include <TestStream.h>

typedef void(*f_ptr)(void);

// COMMAND TEST
void testCommand() { std::cout << "Test command :)"; }

class CommandTest: public TestStream {
protected:
	const std::string testName = "test";
	Command cmd;
	virtual void SetUp() { cmd.init(testName.c_str(), testCommand); }
};

TEST_F(CommandTest, testName) {
	EXPECT_EQ(1, cmd.isNamed(testName.c_str()));
}

TEST_F(CommandTest, testExe) {
	cmd.exe();
	EXPECT_EQ("Test command :)", buffer.str());
}

// COMMANDS TEST

void test1() { std::cout << "empty"; }
void test2() { std::cout << "test command"; }
void test3() { std::cout << "lorem ipsum dolor"; }

class CommandsTest: public TestStream {
protected:
	Commands cmds;
	const f_ptr functionsToTest[3] = {test1, test2, test3};
	CommandsTest() : cmds(0) { }

	virtual void SetUp() {
		cmds.addCommand("", functionsToTest[0]);
		cmds.addCommand("test", functionsToTest[1]);
		cmds.addCommand("lorem", functionsToTest[2]);
	}
};

TEST_F(CommandsTest, checkCommandsNames) {

	EXPECT_STREQ("", cmds[0].getName());
	EXPECT_STREQ("test", cmds[1].getName());
	EXPECT_STREQ("lorem", cmds[2].getName());
}

TEST_F(CommandsTest, checkFunctions) {
	std::string expected[] = {"empty", "test command", "lorem ipsum dolor" };

	for(unsigned i=0; i<cmds.len(); i++)
	{
		cmds[i].exe();
		EXPECT_EQ(expected[i], buffer.str());
		buffer.str(std::string());
	}
}

TEST_F(CommandsTest, checkAutoExe) {
	std::string names[] = {"", "test", "lorem" };
	std::string expected[] = {"empty", "test command", "lorem ipsum dolor" };

	for(unsigned i=0; i<cmds.len(); i++)
	{
		cmds.exe(names[i].c_str());
		EXPECT_EQ(expected[i], buffer.str());
		buffer.str(std::string());
	}
}
