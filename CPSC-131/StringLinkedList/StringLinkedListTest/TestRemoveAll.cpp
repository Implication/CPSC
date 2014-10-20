#include "gtest\gtest.h"
#include "StringLinkedList.h"

/*
To test removeAll(const string& e) function.
  1. emptyList: in an empty list, remove an element
  2. inGroupOrder: same elements are next to each other
  3. inRandomOrder: same elements are not next to each other
*/

// Test case 1: empty list
TEST(TestRemoveAll, emptyList) {
	StringLinkedList l;
	EXPECT_EQ("", l.toString());

	// unmatched element
	l.removeAll("A");
	EXPECT_EQ("", l.toString());
}

// Test case 2: remain no element
TEST(TestRemoveAll, inGroupOrder) {
	StringLinkedList l;
	l.addFront("B");
	l.addFront("B");
	l.addFront("A");
	l.addFront("A");
	l.addFront("A");
	
	// unmatched element
	l.removeAll("C");
	EXPECT_EQ("A->A->A->B->B", l.toString());
	
	// remove elements at the back
	l.removeAll("B");
	EXPECT_EQ("A->A->A", l.toString());

	// remove elements at the front
	l.removeAll("A");
	EXPECT_EQ("", l.toString());
}

// Test case 2: remain no element
TEST(TestRemoveAll, inRandomOrder) {
	StringLinkedList l;
	l.addFront("B");
	l.addFront("A");
	l.addFront("B");
	l.addFront("C");
	l.addFront("A");
	l.addFront("B");
	l.addFront("A");
	
	// 
	l.removeAll("A");
	EXPECT_EQ("B->C->B->B", l.toString());
}