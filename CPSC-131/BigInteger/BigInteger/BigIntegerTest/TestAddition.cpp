#include "BigInteger.h"
#include "BigIntegerException.h"
#include "gtest\gtest.h"

/**
*	To test BigInteger addition operator
*	2 cases:
*		1. same length
*		2. different length
*		3. add 0
*/

/**
*	Case 1
*/
TEST(testAddition, sameLength) {
	BigInteger bigInt1("123");
	BigInteger bigInt2("456");

	BigInteger result = bigInt1 + bigInt2;
	EXPECT_EQ("579", result.toString());

	result = bigInt2 + bigInt1;
	EXPECT_EQ("579", result.toString());

	bigInt1 = BigInteger("12345678901234567890");
	bigInt2 = BigInteger("98765432109876543210");

	result = bigInt1 + bigInt2;
	EXPECT_EQ("111111111011111111100", result.toString());

	result = bigInt2 + bigInt1;
	EXPECT_EQ("111111111011111111100", result.toString());
}

/**
*	Case 2
*/
TEST(testAddition, differentLength) {
	BigInteger bigInt1("99123");
	BigInteger bigInt2("456");

	BigInteger result = bigInt1 + bigInt2;
	EXPECT_EQ("99579", result.toString());

	// different position
	result = bigInt2 + bigInt1;
	EXPECT_EQ("99579", result.toString());

	bigInt1 = BigInteger("99999999991234567890");
	bigInt2 = BigInteger("9876543210");

	result = bigInt1 + bigInt2;
	EXPECT_EQ("100000000001111111100", result.toString());

	// different position
	result = bigInt2 + bigInt1;
	EXPECT_EQ("100000000001111111100", result.toString());
}

/**
*	Case 3
*/
TEST(testAddition, addZero) {
	BigInteger bigInt1("12345678901234567890");
	BigInteger bigInt2("0");

	BigInteger result = bigInt1 + bigInt2;
	EXPECT_EQ("12345678901234567890", result.toString());

	result = bigInt2 + bigInt1;
	EXPECT_EQ("12345678901234567890", result.toString());
}