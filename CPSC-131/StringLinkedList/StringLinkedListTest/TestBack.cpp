#include "gtest\gtest.h"
#include "StringLinkedList.h"

/*
To test back() function
  1. back: to test the returned value of the last node
  2. emptyException: EmptyException should be thrown if the list
		is empty
*/

// Test case 1: front
TEST(TestBack, front) {
	StringLinkedList l;

	l.addFront("A");
	EXPECT_EQ("A", l.back());

	l.addFront("B");
	EXPECT_EQ("A", l.back());
}

// Test case 2: emptyException
TEST(TestBack, emptyException) {
	StringLinkedList l;
	EXPECT_THROW(l.back(), EmptyException);
}