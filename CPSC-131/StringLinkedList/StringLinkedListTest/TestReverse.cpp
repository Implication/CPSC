#include "gtest\gtest.h"
#include "StringLinkedList.h"

/*
To test reverse() function.
  1. emptyList: reverse an empty list
  2. listOfOneElement: reverse a 1-element list
  3. listOfTwoElements: reverse a 2-element list
  4. listOfMoreThanTwoElements: reverse a 3-element list
*/

// Test case 1: empty list
TEST(TestReverse, emptyList) {
	StringLinkedList l;
	EXPECT_EQ("", l.toString());
	l.reverse();
	EXPECT_EQ("", l.toString());
}

// Test case 2: list of 1 element
TEST(TestReverse, listOfOneElement) {
	StringLinkedList l;
	l.addFront("A");
	EXPECT_EQ("A", l.toString());
	l.reverse();
	EXPECT_EQ("A", l.toString());
}

// Test case 3: list of 2 elements
TEST(TestReverse, listOfTwoElements) {
	StringLinkedList l;
	l.addFront("A");
	l.addFront("B");
	EXPECT_EQ("B->A", l.toString());
	l.reverse();
	EXPECT_EQ("A->B", l.toString());
}

// Test case 4: list of more-than-2 elements (e.g. 3)
TEST(TestReverse, listOfMoreThanTwoElements) {
	StringLinkedList l;
	l.addFront("A");
	l.addFront("B");
	l.addFront("C");
	EXPECT_EQ("C->B->A", l.toString());
	l.reverse();
	EXPECT_EQ("A->B->C", l.toString());
}