//#include "gtest\gtest.h"
//#include "GenericDLList.cpp"
//#include <string>
//
//// To test get(index) function.
////  1. removeAtFront: to test the returned value when removing at front
////		of the list
////  2. removeAtBack: to test the returned value when removing at back
////		of the list
////  3. removeAtMiddle: to test the returned value when removing at middle
////		of the list
////  4. throwEmptyException: to check if the EmptyException is thrown when the
////        list is empty
////  5. throwOutOfBoundException: to check if the OutOfBoundException is thrown 
////        when the index is out of bound in both cases of positive and 
////        negative indexes
//
//// Test case 1: removeAtFront
//TEST(TestRemoveIndex, removeAtFront) {
//	GenericDLList<std::string> l;
//	l.addFront("A");
//	l.addFront("B");
//	l.addFront("C");
//
//	l.remove(0);
//	EXPECT_EQ("B->A", l.nextDirString());
//	EXPECT_EQ("B<-A", l.prevDirString());
//
//	l.remove(0);
//	EXPECT_EQ("A", l.nextDirString());
//	EXPECT_EQ("A", l.prevDirString());
//
//	l.remove(0);
//	EXPECT_EQ("", l.nextDirString());
//	EXPECT_EQ("", l.prevDirString());
//}
//
//// Test case 2: removeAtBack
//TEST(TestRemoveIndex, removeAtBack) {
//	GenericDLList<std::string> l;
//	l.addFront("A");
//	l.addFront("B");
//	l.addFront("C");
//
//	l.remove(2);
//	EXPECT_EQ("C->B", l.nextDirString());
//	EXPECT_EQ("C<-B", l.prevDirString());
//
//	l.remove(1);
//	EXPECT_EQ("C", l.nextDirString());
//	EXPECT_EQ("C", l.prevDirString());
//
//	l.remove(0);
//	EXPECT_EQ("", l.nextDirString());
//	EXPECT_EQ("", l.prevDirString());
//}
//
//// Test case 3: removeAtMiddle
//TEST(TestRemoveIndex, removeAtMiddle) {
//	GenericDLList<std::string> l;
//	l.addFront("A");
//	l.addFront("B");
//	l.addFront("C");
//	l.addFront("D");
//
//	l.remove(2);
//	EXPECT_EQ("D->C->A", l.nextDirString());
//	EXPECT_EQ("D<-C<-A", l.prevDirString());
//
//	l.remove(1);
//	EXPECT_EQ("D->A", l.nextDirString());
//	EXPECT_EQ("D<-A", l.prevDirString());
//}
//
//// Test case 4: throwEmptyException
//TEST(TestRemoveIndex, throwEmptyException) {
//	GenericDLList<std::string> l;
//
//	EXPECT_THROW(l.remove(0), EmptyException);
//	EXPECT_THROW(l.remove(-1), EmptyException);
//	EXPECT_THROW(l.remove(-2147483647), EmptyException);
//}
//
//// Test case 5: throwOutOfBoundException
//TEST(TestRemoveIndex, throwOutOfBoundException) {
//	GenericDLList<std::string> l;
//	l.addFront("A");
//
//	EXPECT_THROW(l.remove(1), OutOfBoundException);
//	EXPECT_THROW(l.remove(-1), OutOfBoundException);
//	EXPECT_THROW(l.remove(-2147483647), OutOfBoundException);
//}