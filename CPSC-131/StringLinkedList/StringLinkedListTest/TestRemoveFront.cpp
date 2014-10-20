#include "gtest\gtest.h"
#include "StringLinkedList.h"

/*
To test removeFront() function.
  1. removeFront: remove an element at the front of the list
  2. emptyException: throw exception if it is an empty list
*/

TEST(TestRemoveFront, removeFront) {
	StringLinkedList l;
	l.addFront("A");
	l.addFront("B");
	l.addFront("C");
	EXPECT_EQ("C->B->A", l.toString());

	l.removeFront();
	EXPECT_EQ("B->A", l.toString());

	l.removeFront();
	EXPECT_EQ("A", l.toString());

	l.removeFront();
	EXPECT_EQ("", l.toString());
}

TEST(TestRemoveFront, EmptyException) {
	StringLinkedList l;
	EXPECT_THROW(l.removeFront(), EmptyException);
}