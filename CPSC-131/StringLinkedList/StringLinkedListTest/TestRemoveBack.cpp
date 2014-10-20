#include "gtest\gtest.h"
#include "StringLinkedList.h"

/*
To test removeBack() function.
  1. removeBack: remove an element at the back of the list
  2. emptyException: throw exception if it is an empty list
*/

TEST(TestRemoveBack, removeBack) {
	StringLinkedList l;
	l.addBack("A");
	l.addBack("B");
	l.addBack("C");
	EXPECT_EQ("A->B->C", l.toString());

	l.removeBack();
	EXPECT_EQ("A->B", l.toString());

	l.removeBack();
	EXPECT_EQ("A", l.toString());

	l.removeBack();
	EXPECT_EQ("", l.toString());
}

TEST(TestRemoveBack, EmptyException) {
	StringLinkedList l;
	EXPECT_THROW(l.removeBack(), EmptyException);
}