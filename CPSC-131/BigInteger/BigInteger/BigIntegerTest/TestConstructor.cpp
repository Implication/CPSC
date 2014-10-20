#include "BigInteger.h"
#include "BigIntegerException.h"
#include "gtest\gtest.h"

/**
*	To test BigInteger constructors using toString function
*	9 cases:
*		1. default constructor
*		2. constructor with a VALID short string argument
*		3. constructor with a VALID long string argument
*		(within long long range)
*		4. constructor with a VALID long string argument
*		(out of long long range)
*		5. constructor with an INVALID short string - exception
*		6. constructor with an INVALID long string - exception
*		7. constructor with an empty string - exception
*		8. constructor with leading 0
*		9. copy constructor
*/

/**
*	Case 1
*/
TEST(TestConstructor, defaultConstructor) {
	BigInteger bigInt1;
	EXPECT_EQ("0", bigInt1.toString());
}

/**
*	Case 2, 3, 4
*/
TEST(TestConstructor, constructorWithValidString) {
	// case 2
	BigInteger bigInt1("123");
	EXPECT_EQ("123", bigInt1.toString());

	// case 3
	BigInteger bigInt2("1234567890123456789");
	EXPECT_EQ("1234567890123456789", bigInt2.toString());

	// case 4
	BigInteger bigInt3("123456789012345678901");
	EXPECT_EQ("123456789012345678901", bigInt3.toString());
}

/**
*	Case 5, 6, 7:
*	(a): derived class
*	(b): base class
*
* Notes: 
*	Because BigIntegerException is base class of NumberFormatException,
*	same error should be able to catch by base class
*/
TEST(TestConstructor, constructorWithInvalidString) {
	// case 5a
	EXPECT_THROW(BigInteger bigInt5("123a"), NumberFormatException);

	// case 5b
	EXPECT_THROW(BigInteger bigInt5("123a"), BigIntegerException);

	// case 6a
	EXPECT_THROW(
		BigInteger bigInt5("123456789012345678901234567890a"), 
		NumberFormatException);

	// case 6b
	EXPECT_THROW(
		BigInteger bigInt5("123456789012345678901234567890a"),
		BigIntegerException);

	// case 7
	EXPECT_THROW(
		BigInteger bigInt5(""),
		BigIntegerException);
}

/**
*	Case 8
*/
TEST(TestConstructor, constructorWithLeadingZero) {
	BigInteger bigInt("000");
	EXPECT_EQ("0", bigInt.toString());

	bigInt = BigInteger("0001");
	EXPECT_EQ("1", bigInt.toString());
}

/**
*	Case 9
*/
TEST(TestConstructor, copyConstructor) {
	BigInteger bigInt1("123");

	BigInteger bigInt2(bigInt1);
	EXPECT_EQ("123", bigInt2.toString());

	bigInt1 = BigInteger("456");
	EXPECT_EQ("123", bigInt2.toString());
}