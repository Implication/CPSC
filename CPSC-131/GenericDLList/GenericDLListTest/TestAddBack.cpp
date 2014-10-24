#include "gtest\gtest.h"
#include "GenericDLList.cpp"
#include <string>

// To test addBack function.
//  1. addBack: to test the correctness of value and its position
//		in the list

// Test case 1: addBack
TEST(TestAddBack, addBack) {
	GenericDLList<std::string> l;

	l.addBack("A");
	EXPECT_EQ("A", l.nextDirString());
	EXPECT_EQ("A", l.prevDirString());

	l.addBack("B");
	EXPECT_EQ("A->B", l.nextDirString());
	EXPECT_EQ("A<-B", l.prevDirString());

	l.addBack("C");
	EXPECT_EQ("A->B->C", l.nextDirString());
	EXPECT_EQ("A<-B<-C", l.prevDirString());
}