#include "gtest\gtest.h"
#include "StringLinkedList.h"

/*
To test insert(int index, const std::string& e) function.
  1. insertAtFront: to test the returned value when inserting at front
		of the list
  2. insertAtBack: to test the returned value when inserting at back
		of the list
  3. insertAtMiddle: to test the returned value when inserting at middle
		of the list
  4. outOfBoundException: to test when the index is out of bound in 
		both cases of positive and negative indexes
*/

// Test case 1: insertAtFront
TEST(TestInsert, insertAtFront) {
	StringLinkedList l;
	l.insert(0, "A");
	EXPECT_EQ("A", l.toString());

	l.insert(0, "B");
	EXPECT_EQ("B->A", l.toString());

	l.insert(0, "C");
	EXPECT_EQ("C->B->A", l.toString());
}

// Test case 2: insertAtBack
TEST(TestInsert, insertAtBack) {
	StringLinkedList l;
	l.insert(0, "A");
	EXPECT_EQ("A", l.toString());

	l.insert(1, "B");
	EXPECT_EQ("A->B", l.toString());

	l.insert(2, "C");
	EXPECT_EQ("A->B->C", l.toString());
}

// Test case 3: insertAtMiddle
TEST(TestInsert, insertAtMiddle) {
	StringLinkedList l;
	l.insert(0, "A");
	l.insert(1, "B");
	EXPECT_EQ("A->B", l.toString());

	l.insert(1, "C");
	EXPECT_EQ("A->C->B", l.toString());

	l.insert(1, "D");
	EXPECT_EQ("A->D->C->B", l.toString());

	l.insert(2, "E");
	EXPECT_EQ("A->D->E->C->B", l.toString());
}

// Test case 4: outOfBoundException
TEST(TestInsert, outOfBoundException) {
	StringLinkedList l;
	EXPECT_THROW(l.insert(1, "A"), OutOfBoundException);
	EXPECT_THROW(l.insert(-1, "A"), OutOfBoundException);

	l.insert(0, "A");
	EXPECT_THROW(l.insert(2, "A"), OutOfBoundException);
	EXPECT_THROW(l.insert(-2147483647, "A"), OutOfBoundException);
}