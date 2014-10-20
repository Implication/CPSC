//#include "gtest\gtest.h"
//#include "GenericDLList.cpp"
//#include <string>
//
//// To test removeBack function.
////  1. removeBack: remove an element at the back of the list
////  2. throwEmptyException: throw exception if it is an empty list
//
//// Test case 1: removeBack
//TEST(TestRemoveBack, removeBack) {
//	GenericDLList<std::string> l;
//	l.addBack("A");
//	l.addBack("B");
//	l.addBack("C");
//	EXPECT_EQ("A->B->C", l.nextDirString());
//	EXPECT_EQ("A<-B<-C", l.prevDirString());
//
//	l.removeBack();
//	EXPECT_EQ("A->B", l.nextDirString());
//	EXPECT_EQ("A<-B", l.prevDirString());
//
//	l.removeBack();
//	EXPECT_EQ("A", l.nextDirString());
//	EXPECT_EQ("A", l.prevDirString());
//
//	l.removeBack();
//	EXPECT_EQ("", l.nextDirString());
//	EXPECT_EQ("", l.prevDirString());
//}
//
//// Test case 2: throwEmptyException
//TEST(TestRemoveBack, throwEmptyException) {
//	GenericDLList<std::string> l;
//	EXPECT_THROW(l.removeBack(), EmptyException);
//}