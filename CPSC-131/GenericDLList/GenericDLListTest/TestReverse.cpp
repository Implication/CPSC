#include "gtest\gtest.h"
#include "GenericDLList.cpp"
#include <string>

// To test reverse() function.
//  1. reverseEmptyList: reverse an empty list
//  2. reverseListOfOneElement: reverse a 1-element list
//  3. reverseListOfTwoElements: reverse a 2-element list
//  4. reverseListOfMoreThanTwoElements: reverse a 3-element list

// Test case 1: reverseEmptyList
TEST(TestReverse, reverseEmptyList) {
	GenericDLList<std::string> l;

	EXPECT_EQ("", l.nextDirString());
	EXPECT_EQ("", l.prevDirString());
	l.reverse();
	EXPECT_EQ("", l.nextDirString());
	EXPECT_EQ("", l.prevDirString());
}

// Test case 2: reverseListOfOneElement
TEST(TestReverse, reverseListOfOneElement) {
	GenericDLList<std::string> l;
	l.addFront("A");

	EXPECT_EQ("A", l.nextDirString());
	EXPECT_EQ("A", l.prevDirString());
	l.reverse();
	EXPECT_EQ("A", l.nextDirString());
	EXPECT_EQ("A", l.prevDirString());
}

// Test case 3: reverseListOfTwoElements
TEST(TestReverse, reverseListOfTwoElements) {
	GenericDLList<std::string> l;
	l.addFront("A");
	l.addFront("B");

	EXPECT_EQ("B->A", l.nextDirString());
	EXPECT_EQ("B<-A", l.prevDirString());
	l.reverse();
	EXPECT_EQ("A->B", l.nextDirString());
	EXPECT_EQ("A<-B", l.prevDirString());
}

// Test case 4: reverseListOfMoreThanTwoElements, list of more-than-2 elements (e.g. 3)
TEST(TestReverse, reverseListOfMoreThanTwoElements) {
	GenericDLList<std::string> l;
	l.addFront("A");
	l.addFront("B");
	l.addFront("C");

	EXPECT_EQ("C->B->A", l.nextDirString());
	EXPECT_EQ("C<-B<-A", l.prevDirString());
	l.reverse();
	EXPECT_EQ("A->B->C", l.nextDirString());
	EXPECT_EQ("A<-B<-C", l.prevDirString());
}