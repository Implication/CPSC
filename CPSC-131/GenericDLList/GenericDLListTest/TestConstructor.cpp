#include "gtest\gtest.h"
#include "GenericDLList.cpp"
#include <string>

// To test default constructor

TEST(TestConstructor, defaultConstructor) {
	GenericDLList<int> iDll;
	EXPECT_EQ("", iDll.nextDirString());
	EXPECT_EQ("", iDll.prevDirString());

	GenericDLList<double> dDll;
	EXPECT_EQ("", dDll.nextDirString());
	EXPECT_EQ("", dDll.prevDirString());

	GenericDLList<std::string> sDll;
	EXPECT_EQ("", sDll.nextDirString());
	EXPECT_EQ("", sDll.prevDirString());
}