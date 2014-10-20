//#include "gtest\gtest.h"
//#include "GenericDLList.cpp"
//#include <string>
//
//// To test back function
////  1. getBack: to test the returned value of the last node
////  2. throwEmptyException: EmptyException should be thrown if the list
////		is empty
//
//// Test case 1: getBack
//TEST(TestBack, getBack) {
//	GenericDLList<std::string> l;
//
//	l.addFront("A");
//	EXPECT_EQ("A", l.back());
//
//	l.addFront("B");
//	EXPECT_EQ("A", l.back());
//}
//
//// Test case 2: throwEmptyException
//TEST(TestBack, throwEmptyException) {
//	GenericDLList<std::string> l;
//	EXPECT_THROW(l.back(), EmptyException);
//}