#include "gtest\gtest.h"
#include "GenericDLList.cpp"
#include <string>

// To test remove(const string& e) function.
//  1. emptyList: in an empty list, remove an element
//  2. listOfOneElement: in a 1-element list,
//		a. remove unmatched element
//		b. remove first element
//  3. listOfTwoElements: in a 2-element list,
//		a. remove unmatched element
//		b. remove first element
//		c. remove second element
//  4. listOfMoreThanTwoElements: in a 3-element list,
//		a. remove middle element

// Test case 1: emptyList
TEST(TestRemove, emptyList) {
	GenericDLList<std::string> l;

	// unmatched element
	EXPECT_FALSE(l.remove("A"));
	EXPECT_EQ("", l.nextDirString());
	EXPECT_EQ("", l.prevDirString());
}

// Test case 2: listOfOneElement
TEST(TestRemove, listOfOneElement) {
	GenericDLList<std::string> l;
	l.addFront("A");
	
	// unmatched element
	EXPECT_FALSE(l.remove("B"));
	EXPECT_EQ("A", l.nextDirString());
	EXPECT_EQ("A", l.prevDirString());
	
	// remove first element
	EXPECT_TRUE(l.remove("A"));
	EXPECT_EQ("", l.nextDirString());
	EXPECT_EQ("", l.prevDirString());
}

// Test case 3: listOfTwoElements
TEST(TestRemove, listOfTwoElements) {
	GenericDLList<std::string> l;
	l.addFront("A");
	l.addFront("B");

	// unmatched element
	EXPECT_FALSE(l.remove("C"));
	EXPECT_EQ("B->A", l.nextDirString());
	EXPECT_EQ("B<-A", l.prevDirString());

	// remove first element
	EXPECT_TRUE(l.remove("B"));
	EXPECT_EQ("A", l.nextDirString());
	EXPECT_EQ("A", l.prevDirString());

	// remove second element
	l.addFront("B");
	EXPECT_TRUE(l.remove("A"));
	EXPECT_EQ("B", l.nextDirString());
	EXPECT_EQ("B", l.prevDirString());
}

// Test case 4: listOfMoreThanTwoElements (e.g. 3)
TEST(TestRemove, listOfMoreThanTwoElements) {
	GenericDLList<std::string> l;
	l.addFront("B");
	l.addFront("A");
	l.addFront("B");
	l.addFront("C");

	// remove middle element
	EXPECT_TRUE(l.remove("B"));
	EXPECT_EQ("C->A->B", l.nextDirString());
	EXPECT_EQ("C<-A<-B", l.prevDirString());
}