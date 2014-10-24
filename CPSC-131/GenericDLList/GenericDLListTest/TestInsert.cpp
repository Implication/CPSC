#include "gtest\gtest.h"
#include "GenericDLList.cpp"
#include <string>

// To test insert function.
//  1. insertAtFront: to test the returned value when inserting at front
//		of the list
//  2. insertAtBack: to test the returned value when inserting at back
//		of the list
//  3. insertAtMiddle: to test the returned value when inserting at middle
//		of the list
//  4. throwOutOfBoundException: to test when the index is out of bound in 
//		both cases of positive and negative indexes

// Test case 1: insertAtFront
TEST(TestInsert, insertAtFront) {
	GenericDLList<std::string> l;
	l.insert(0, "A");
	EXPECT_EQ("A", l.nextDirString());
	EXPECT_EQ("A", l.prevDirString());

	l.insert(0, "B");
	EXPECT_EQ("B->A", l.nextDirString());
	EXPECT_EQ("B<-A", l.prevDirString());

	l.insert(0, "C");
	EXPECT_EQ("C->B->A", l.nextDirString());
	EXPECT_EQ("C<-B<-A", l.prevDirString());
}

// Test case 2: insertAtBack
TEST(TestInsert, insertAtBack) {
	GenericDLList<std::string> l;
	l.insert(0, "A");
	EXPECT_EQ("A", l.nextDirString());
	EXPECT_EQ("A", l.prevDirString());

	l.insert(1, "B");
	EXPECT_EQ("A->B", l.nextDirString());
	EXPECT_EQ("A<-B", l.prevDirString());

	l.insert(2, "C");
	EXPECT_EQ("A->B->C", l.nextDirString());
	EXPECT_EQ("A<-B<-C", l.prevDirString());
}

// Test case 3: insertAtMiddle
TEST(TestInsert, insertAtMiddle) {
	GenericDLList<std::string> l;
	l.insert(0, "A");
	l.insert(1, "B");
	EXPECT_EQ("A->B", l.nextDirString());
	EXPECT_EQ("A<-B", l.prevDirString());

	l.insert(1, "C");
	EXPECT_EQ("A->C->B", l.nextDirString());
	EXPECT_EQ("A<-C<-B", l.prevDirString());

	l.insert(1, "D");
	EXPECT_EQ("A->D->C->B", l.nextDirString());
	EXPECT_EQ("A<-D<-C<-B", l.prevDirString());

	l.insert(2, "E");
	EXPECT_EQ("A->D->E->C->B", l.nextDirString());
	EXPECT_EQ("A<-D<-E<-C<-B", l.prevDirString());
}

// Test case 4: throwOutOfBoundException
TEST(TestInsert, throwOutOfBoundException) {
	GenericDLList<std::string> l;
	EXPECT_THROW(l.insert(1, "A"), OutOfBoundException);
	EXPECT_THROW(l.insert(-1, "A"), OutOfBoundException);

	l.insert(0, "A");
	EXPECT_THROW(l.insert(2, "A"), OutOfBoundException);
	EXPECT_THROW(l.insert(-2147483647, "A"), OutOfBoundException);
}