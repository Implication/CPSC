#include "gtest\gtest.h"
#include "StringLinkedList.h"

/*
To test addBack(const string& e) function.
  1. correctListOfValues: to test the correctness of value and its position
		in the list
*/

// Test case 1: correctListOfValues
TEST(TestAddBack, correctListOfValues) {
	StringLinkedList l;
	EXPECT_EQ("", l.toString());

	l.addBack("A");
	EXPECT_EQ("A", l.toString());

	l.addBack("B");
	EXPECT_EQ("A->B", l.toString());

	l.addBack("C");
	EXPECT_EQ("A->B->C", l.toString());
}