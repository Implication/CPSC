#include "gtest\gtest.h"
#include "GenericDLList.cpp"
#include <string>

// To test removeAll(const string& e) function.
//  1. emptyList: in an empty list, remove an element
//  2. inGroupOrder: same elements are next to each other
//  3. inRandomOrder: same elements are not next to each other

// Test case 1: emptyList
TEST(TestRemoveAll, emptyList) {
	GenericDLList<std::string> l;

	// unmatched element
	EXPECT_FALSE(l.removeAll("A"));
	EXPECT_EQ("", l.nextDirString());
	EXPECT_EQ("", l.prevDirString());
}

// Test case 2: inGroupOrder
TEST(TestRemoveAll, inGroupOrder) {
	GenericDLList<std::string> l;
	l.addFront("B");
	l.addFront("B");
	l.addFront("A");
	l.addFront("A");
	l.addFront("A");
	
	// unmatched element
	l.removeAll("C");
	EXPECT_EQ("A->A->A->B->B", l.nextDirString());
	EXPECT_EQ("A<-A<-A<-B<-B", l.prevDirString());
	
	// remove elements at the back
	l.removeAll("B");
	EXPECT_EQ("A->A->A", l.nextDirString());
	EXPECT_EQ("A<-A<-A", l.prevDirString());

	// remove elements at the front
	l.removeAll("A");
	EXPECT_EQ("", l.nextDirString());
	EXPECT_EQ("", l.prevDirString());
}

// Test case 2: inRandomOrder
TEST(TestRemoveAll, inRandomOrder) {
	GenericDLList<std::string> l;
	l.addFront("B");
	l.addFront("A");
	l.addFront("B");
	l.addFront("C");
	l.addFront("A");
	l.addFront("B");
	l.addFront("A");
	
	l.removeAll("A");
	EXPECT_EQ("B->C->B->B", l.nextDirString());
	EXPECT_EQ("B<-C<-B<-B", l.prevDirString());
}