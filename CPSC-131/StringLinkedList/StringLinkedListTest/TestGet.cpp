#include "gtest\gtest.h"
#include "StringLinkedList.h"

/*
To test get(int index) function.
  1. returnCorrectValue: to test the returned value at specific position
  2. emptyException: to test if the list is empty
  3. outOfBoundException: to test when the index is out of bound in 
		both cases of positive and negative indexes
*/

// Test case 1: returnCorrectValue 
TEST(TestGet, returnCorrectValue) {
	StringLinkedList l;
	l.addFront("A");
	EXPECT_EQ("A", l.get(0));

	l.addFront("B");
	EXPECT_EQ("B", l.get(0));
	EXPECT_EQ("A", l.get(1));
}

// Test case 2: emptyException
TEST(TestGet, emptyException) {
	StringLinkedList l;
	EXPECT_THROW(l.get(-1), EmptyException);
	EXPECT_THROW(l.get(0), EmptyException);
}

// Test case 3: outOfBoundException
TEST(TestGet, outOfBoundException) {
	StringLinkedList l;
	l.addFront("A");
	EXPECT_THROW(l.get(-2147483647), OutOfBoundException);
	EXPECT_THROW(l.get(1), OutOfBoundException);

	l.addFront("B");
	EXPECT_THROW(l.get(2), OutOfBoundException);
}