#include "gtest\gtest.h"
#include "StringLinkedList.h"

/*
To test get(int index) function.
  1. removeAtFront: to test the returned value when removeing at front
		of the list
  2. removeAtBack: to test the returned value when removeing at back
		of the list
  3. removeAtMiddle: to test the returned value when removeing at middle
		of the list
  4. emptyException: to check if the EmptyException is thrown when the
        list is empty
  5. outOfBoundException: to check if the OutOfBoundException is thrown 
        when the index is out of bound in both cases of positive and 
        negative indexes
*/

// Test case 1: removeAtFront
TEST(TestRemoveIndex, removeAtFront) {
	StringLinkedList l;
	l.addFront("A");
	l.addFront("B");
	l.addFront("C");

	l.remove(0);
	EXPECT_EQ("B->A", l.toString());

	l.remove(0);
	EXPECT_EQ("A", l.toString());

	l.remove(0);
	EXPECT_EQ("", l.toString());
}

// Test case 2: removeAtBack
TEST(TestRemoveIndex, removeAtBack) {
	StringLinkedList l;
	l.addFront("A");
	l.addFront("B");
	l.addFront("C");

	l.remove(2);
	EXPECT_EQ("C->B", l.toString());

	l.remove(1);
	EXPECT_EQ("C", l.toString());

	l.remove(0);
	EXPECT_EQ("", l.toString());
}

// Test case 3: removeAtMiddle
TEST(TestRemoveIndex, removeAtMiddle) {
	StringLinkedList l;
	l.addFront("A");
	l.addFront("B");
	l.addFront("C");

	l.remove(1);
	EXPECT_EQ("C->A", l.toString());
}

// Test case 4: emptyException
TEST(TestRemoveIndex, emptyException) {
	StringLinkedList l;

	EXPECT_THROW(l.remove(0), EmptyException);
	EXPECT_THROW(l.remove(-1), EmptyException);
	EXPECT_THROW(l.remove(-2147483647), EmptyException);
}

// Test case 5: outOfBoundException
TEST(TestRemoveIndex, outOfBoundException) {
	StringLinkedList l;
	l.addFront("A");

	EXPECT_THROW(l.remove(1), OutOfBoundException);
	EXPECT_THROW(l.remove(-1), OutOfBoundException);
	EXPECT_THROW(l.remove(-2147483647), OutOfBoundException);
}