#include "BigInteger.h"
#include "BigIntegerException.h"
#include "gtest\gtest.h"

/**
*	To test BigInteger multiplication operator
*	2 cases:
*		1. same length
*		2. different length
*		3. multiply 0
*/

/**
*	Case 1
*/
TEST(testMultiplication, sameLength) {
	BigInteger bigInt1("123");
	BigInteger bigInt2("456");

	BigInteger result = bigInt1 * bigInt2;
	EXPECT_EQ("56088", result.toString());

	result = bigInt2 * bigInt1;
	EXPECT_EQ("56088", result.toString());

	bigInt1 = BigInteger("12345678901234567890");
	bigInt2 = BigInteger("98765432109876543210");

	result = bigInt1 * bigInt2;
	EXPECT_EQ("1219326311370217952237463801111263526900", result.toString());

	result = bigInt2 * bigInt1;
	EXPECT_EQ("1219326311370217952237463801111263526900", result.toString());
}

/**
*	Case 2
*/
TEST(testMultiplication, differentLength) {
	BigInteger bigInt1("99123");
	BigInteger bigInt2("456");

	BigInteger result = bigInt1 * bigInt2;
	EXPECT_EQ("45200088", result.toString());

	result = bigInt2 * bigInt1;
	EXPECT_EQ("45200088", result.toString());

	bigInt1 = BigInteger("99999999991234567890");
	bigInt2 = BigInteger("9876543210");

	result = bigInt1 * bigInt2;
	EXPECT_EQ("987654320913427831011263526900", result.toString());

	// 
	result = bigInt2 * bigInt1;
	EXPECT_EQ("987654320913427831011263526900", result.toString());
}

/**
*	Case 3
*/
TEST(testMultiplication, multiplyZero) {
	BigInteger bigInt1("12345678901234567890");
	BigInteger bigInt2("0");

	BigInteger result = bigInt1 * bigInt2;
	EXPECT_EQ("0", result.toString());

	result = bigInt2 * bigInt1;
	EXPECT_EQ("0", result.toString());
}