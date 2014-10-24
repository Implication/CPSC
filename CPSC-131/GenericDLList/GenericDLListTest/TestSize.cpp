#include "gtest\gtest.h"
#include "GenericDLList.cpp"
#include <string>

// To test size() function: the number of nodes should only change in these
//  following functions: addBack, addFront, insert, remove, removeAll, 
//  removeBack, removeFront; and stay unchanged on other functions

TEST(TestSize, defaultConstructor) {
	// default constructor
	GenericDLList<std::string> l;
	EXPECT_EQ(0, l.size());
}

TEST(TestSize, front) {
	GenericDLList<std::string> l;
	l.addFront("A");

	l.front();
	EXPECT_EQ(1, l.size());
}

TEST(TestSize, back) {
	GenericDLList<std::string> l;
	l.addFront("A");

	l.back();
	EXPECT_EQ(1, l.size());
}

TEST(TestSize, addFront) {
	GenericDLList<std::string> l;

	// addFront
	l.addFront("A");
	EXPECT_EQ(1, l.size());
}

TEST(TestSize, removeFront) {
	GenericDLList<std::string> l;
	l.addFront("A");

	// removeFront
	l.removeFront();
	EXPECT_EQ(0, l.size());
	EXPECT_THROW(l.removeFront(), EmptyException);
	EXPECT_EQ(0, l.size());
}

TEST(TestSize, addBack) {
	GenericDLList<std::string> l;

	// addBack
	l.addBack("B");
	EXPECT_EQ(1, l.size());
}

TEST(TestSize, removeBack) {
	GenericDLList<std::string> l;
	l.addFront("B");

	// removeBack
	l.removeBack();
	EXPECT_EQ(0, l.size());
	EXPECT_THROW(l.removeBack(), EmptyException);
	EXPECT_EQ(0, l.size());
}

TEST(TestSize, get) {
	GenericDLList<std::string> l;

	// get
	l.addFront("A");
	l.get(0);
	EXPECT_EQ(1, l.size());
}

TEST(TestSize, insert) {
	GenericDLList<std::string> l;

	// insert
	l.insert(0, "A");
	EXPECT_EQ(1, l.size());
}

TEST(TestSize, remove) {
	GenericDLList<std::string> l;
	l.addFront("A");
	l.addFront("A");
	l.addFront("B");

	// remove
	l.remove("A");
	EXPECT_EQ(2, l.size());
}

TEST(TestSize, removeAll) {
	GenericDLList<std::string> l;
	l.addFront("B");
	l.addFront("B");
	l.addFront("A");
	l.addFront("A");
	l.addFront("A");
	
	// insert
	l.removeAll("A");
	EXPECT_EQ(2, l.size());
}

TEST(TestSize, reverse) {
	GenericDLList<std::string> l;
	l.addFront("A");
	l.addFront("A");
	l.addFront("B");

	// reverse
	l.reverse();
	EXPECT_EQ(3, l.size());
}