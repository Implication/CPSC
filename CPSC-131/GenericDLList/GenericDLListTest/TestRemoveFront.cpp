//#include "gtest\gtest.h"
//#include "GenericDLList.cpp"
//#include <string>
//
//// To test removeFront() function.
////  1. removeFront: remove an element at the front of the list
////  2. throwEmptyException: throw exception if it is an empty list
//
//// Test case 1: removeFront
//TEST(TestRemoveFront, removeFront) {
//	GenericDLList<std::string> l;
//	l.addFront("A");
//	l.addFront("B");
//	l.addFront("C");
//	EXPECT_EQ("C->B->A", l.nextDirString());
//	EXPECT_EQ("C<-B<-A", l.prevDirString());
//
//	l.removeFront();
//	EXPECT_EQ("B->A", l.nextDirString());
//	EXPECT_EQ("B<-A", l.prevDirString());
//
//	l.removeFront();
//	EXPECT_EQ("A", l.nextDirString());
//	EXPECT_EQ("A", l.prevDirString());
//
//	l.removeFront();
//	EXPECT_EQ("", l.nextDirString());
//	EXPECT_EQ("", l.prevDirString());
//}
//
//// Test case 2: throwEmptyException
//TEST(TestRemoveFront, throwEmptyException) {
//	GenericDLList<std::string> l;
//	EXPECT_THROW(l.removeFront(), EmptyException);
//}