#include "gtest\gtest.h"
#include "StringLinkedList.h"

/*
To test front() function
  1. front: to test the returned value of the first node
  2. emptyException: EmptyException should be thrown if the list
		is empty
*/

// Test case 1: front
TEST(TestFront, front) {
	StringLinkedList l;

	l.addFront("A");
	EXPECT_EQ("A", l.front());

	l.addFront("B");
	EXPECT_EQ("B", l.front());
}

// Test case 2: emptyException
TEST(TestFront, emptyException) {
	StringLinkedList l;
	EXPECT_THROW(l.front(), EmptyException);
}