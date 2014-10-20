#include "gtest\gtest.h"
#include "StringLinkedList.h"

/*
To test empty() function.
  1. isEmptyList: to test if the list is empty
*/

// Test case 1: isEmptyList
TEST(TestEmpty, isEmptyList) {
	StringLinkedList l;
	EXPECT_TRUE(l.empty());

	l.addFront("A");
	EXPECT_FALSE(l.empty());
}