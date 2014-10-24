#include "gtest\gtest.h"
#include "GenericDLList.cpp"
#include <string>

// To test front() function
//  1. getFront: to test the returned value of the first node
//  2. throwEmptyException: EmptyException should be thrown if the list
//		is empty

// Test case 1: getFront
TEST(TestFront, getFront) {
	GenericDLList<std::string> l;

	l.addFront("A");
	EXPECT_EQ("A", l.front());

	l.addFront("B");
	EXPECT_EQ("B", l.front());
}

// Test case 2: throwEmptyException
TEST(TestFront, throwEmptyException) {
	GenericDLList<std::string> l;
	EXPECT_THROW(l.front(), EmptyException);
}