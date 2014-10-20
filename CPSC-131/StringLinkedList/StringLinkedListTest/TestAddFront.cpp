#include "gtest\gtest.h"
#include "StringLinkedList.h"

/*
To test addFront(const string& e) function.
  1. correctListOfValues: to test the correctness of value and its position
		in the list
*/

// Test case 1: correctListOfValues
TEST(TestAddFront, AddFrontEachElement) {
	StringLinkedList l;
	EXPECT_EQ("", l.toString());

	l.addFront("A");
	EXPECT_EQ("A", l.toString());

	l.addFront("B");
	EXPECT_EQ("B->A", l.toString());

	l.addFront("C");
	EXPECT_EQ("C->B->A", l.toString());
}