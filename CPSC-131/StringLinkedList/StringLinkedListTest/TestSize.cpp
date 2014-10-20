#include "gtest\gtest.h"
#include "StringLinkedList.h"

/*
To test size() function: the number of nodes should only change in these
following functions: addBack, addFront, insert, remove, removeAll, 
removeBack, removeFront; and stay unchanged on other functions
*/

TEST(TestSize, defaultConstructor) {
	// default constructor
	StringLinkedList l;
	EXPECT_EQ(0, l.size());
}

TEST(TestSize, front) {
	StringLinkedList l;
	l.addFront("A");
	l.front();
	EXPECT_EQ(1, l.size());
}

TEST(TestSize, back) {
	StringLinkedList l;
	l.addFront("A");
	l.back();
	EXPECT_EQ(1, l.size());
}

TEST(TestSize, addFront) {
	StringLinkedList l;

	// addFront
	l.addFront("A");
	EXPECT_EQ(1, l.size());
}

TEST(TestSize, removeFront) {
	StringLinkedList l;
	l.addFront("A");

	// removeFront
	l.removeFront();
	EXPECT_EQ(0, l.size());
	EXPECT_THROW(l.removeFront(), EmptyException);
	EXPECT_EQ(0, l.size());
}

TEST(TestSize, addBack) {
	StringLinkedList l;
	// addBack
	l.addBack("B");
	EXPECT_EQ(1, l.size());
}

TEST(TestSize, removeBack) {
	StringLinkedList l;
	l.addFront("B");

	// removeBack
	l.removeBack();
	EXPECT_EQ(0, l.size());
	EXPECT_THROW(l.removeBack(), EmptyException);
	EXPECT_EQ(0, l.size());
}

TEST(TestSize, get) {
	StringLinkedList l;

	// get
	l.addFront("A");
	l.get(0);
	EXPECT_EQ(1, l.size());
}

TEST(TestSize, insert) {
	StringLinkedList l;

	// insert
	l.insert(0, "A");
	EXPECT_EQ(1, l.size());
}

TEST(TestSize, remove) {
	StringLinkedList l;
	l.addFront("A");
	l.addFront("A");
	l.addFront("B");

	// remove
	l.remove("A");
	EXPECT_EQ(2, l.size());
}

TEST(TestSize, removeAll) {
	StringLinkedList l;
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
	StringLinkedList l;
	l.addFront("A");
	l.addFront("A");
	l.addFront("B");

	// reverse
	l.reverse();
	EXPECT_EQ(3, l.size());
}