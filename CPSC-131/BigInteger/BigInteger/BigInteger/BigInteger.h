#ifndef BIG_INTEGER_H
#define BIG_INTEGER_H

#include "BigIntegerException.h"

/**
Recall from integer type that covers largest range is 
long long, which is from –9,223,372,036,854,775,808 to 
9,223,372,036,854,775,807. You don't want these limitation
on how large number you can use.

Your task is to design this BigInteger class and implement
its operators to overcome this limitation of long long type.
Here are your tasks:
1. constructors:
  a. default constructor: should store number 0
  b. constructor with one string argument: store value
and throw NumberFormatException if argument is 
a empty string or string with non-numeric characters
  c. copy construtor: to clone a copy of an object instead
of just a pointer (see shadow copy behavior)

2. destructor: as a rule of thumb, when you allocate memory, 
clean up memory.

3. toString: return the number in a string format

4. operator+: to add two BigInteger objects

5. operator*: to multiply two BigInteger objects

With all above requirements, design an internal/private data 
members that are approriate to all above functions. See the
test cases (BigIntegerTest) to see its expected usage.
*/
class BigInteger {
private:
	/** 
	Design your internal structure here
	*/
	// your code starts from below
	string number;
	int size;


	// ... and ends above

public:
	// default constructor
	BigInteger();

	// constructor with one string argument
	BigInteger(std::string value) throw ();

	// copy constructor
	BigInteger(const BigInteger& bigInt);

	// assignment operator
	BigInteger& operator=(const BigInteger& bigInt);

	// destructor
	~BigInteger();

	// print the number without leading zero
	std::string toString();

	// addition operator
	friend BigInteger operator+(const BigInteger& leftNum, const BigInteger& rightNum);

	// multiplication operator
	friend BigInteger operator*(const BigInteger& leftNum, const BigInteger& rightNum);
};

#endif