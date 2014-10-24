#include "gtest\gtest.h"
#include "GenericDLList.cpp"
#include <string>

// To test addFront function.
//  1. addFront: to test the correctness of value and its position
//		in the list

// Test case 1: addFront
TEST(TestAddFront, addFront) {
	GenericDLList<std::string> l;

	l.addFront("A");
	EXPECT_EQ("A", l.nextDirString());
	EXPECT_EQ("A", l.prevDirString());

	l.addFront("B");
	EXPECT_EQ("B->A", l.nextDirString());
	EXPECT_EQ("B<-A", l.prevDirString());

	l.addFront("C");
	EXPECT_EQ("C->B->A", l.nextDirString());
	EXPECT_EQ("C<-B<-A", l.prevDirString());
}