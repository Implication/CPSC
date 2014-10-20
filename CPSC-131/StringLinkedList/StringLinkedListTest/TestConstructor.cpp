#include "gtest\gtest.h"
#include "StringLinkedList.h"

/*
To test StringLinkedList() default constructor
*/

TEST(TestConstructor, defaultConstructor) {
	StringLinkedList l;
	EXPECT_EQ("", l.toString());
}