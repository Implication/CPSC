//#include "gtest\gtest.h"
//#include "GenericDLList.cpp"
//#include <string>
//
//// To test get(index) function.
////  1. getElementByIndex: to test the returned value at specific index
////  2. throwEmptyException: to test if the list is empty
////  3. throwOutOfBoundException: to test when the index is out of bound in 
////		both cases of positive and negative indexes
//
//// Test case 1: getElementByIndex 
//TEST(TestGet, getElementByIndex) {
//	GenericDLList<std::string> l;
//	l.addFront("A");
//	EXPECT_EQ("A", l.get(0));
//
//	l.addFront("B");
//	EXPECT_EQ("B", l.get(0));
//	EXPECT_EQ("A", l.get(1));
//}
//
//// Test case 2: throwEmptyException
//TEST(TestGet, throwEmptyException) {
//	GenericDLList<std::string> l;
//	EXPECT_THROW(l.get(-1), EmptyException);
//	EXPECT_THROW(l.get(0), EmptyException);
//	EXPECT_THROW(l.get(1), EmptyException);
//}
//
//// Test case 3: throwOutOfBoundException
//TEST(TestGet, throwOutOfBoundException) {
//	GenericDLList<std::string> l;
//	l.addFront("A");
//	EXPECT_THROW(l.get(-2147483647), OutOfBoundException);
//	EXPECT_THROW(l.get(1), OutOfBoundException);
//
//	l.addFront("B");
//	EXPECT_THROW(l.get(2), OutOfBoundException);
//}