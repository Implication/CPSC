#include "gtest\gtest.h"
#include "StringLinkedList.h"

/*
To test remove(const string& e) function.
  1. emptyList: in an empty list, remove an element
  2. listOfOneElement: in a 1-element list,
		a. remove unmatched element
		b. remove first element
  3. listOfTwoElements: in a 2-element list,
		a. remove unmatched element
		b. remove first element
		c. remove second element
  4. listOfMoreThanTwoElements: in a 3-element list,
		a. remove middle element
*/

//Test case 1: empty list
TEST(TestRemove, emptyList) {
	StringLinkedList l;
	EXPECT_EQ("", l.toString());

	// unmatched element
	EXPECT_FALSE(l.remove("A"));
	EXPECT_EQ("", l.toString());
}

// Test case 2: list of 1 element
TEST(TestRemove, listOfOneElement) {
	StringLinkedList l;
	l.addFront("A");
	
	// unmatched element
EXPECT_FALSE(l.remove("B"));
EXPECT_EQ("A", l.toString());
	
	// remove first element
	EXPECT_TRUE(l.remove("A"));
	EXPECT_EQ("", l.toString());
}

// Test case 3: list of 2 elements
TEST(TestRemove, listOfTwoElements) {
	StringLinkedList l;
	l.addFront("A");
	l.addFront("B");

	// unmatched element
	EXPECT_FALSE(l.remove("C"));
	EXPECT_EQ("B->A", l.toString());

	// remove first element
	EXPECT_TRUE(l.remove("B"));
EXPECT_EQ("A", l.toString());

	// remove second element
	l.addFront("B");
	EXPECT_TRUE(l.remove("A"));
	EXPECT_EQ("B", l.toString());
}

// Test case 4: list of more-than-2 elements (e.g. 3)
TEST(TestRemove, listOfMoreThanTwoElements) {
	StringLinkedList l;
	l.addFront("B");
	l.addFront("A");
	l.addFront("B");
	l.addFront("C");

	// remove middle element
	EXPECT_TRUE(l.remove("B"));
	EXPECT_EQ("C->A->B", l.toString());
}