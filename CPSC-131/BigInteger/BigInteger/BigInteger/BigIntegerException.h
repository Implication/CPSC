#ifndef BIG_INTEGER_EXCEPTION_H
#define BIG_INTEGER_EXCEPTION_H

#include <string>

using namespace std;

/** 
BigIntegerException: base class
This class is to catch all exceptions related to
BigInteger class

### You don't need to modify anything here	###
### Read and understand what it does		###
*/
class BigIntegerException {
private:
	string errMsg;

public:
	BigIntegerException(const string& err)
		: errMsg(err) { }
	string getMessage() const { return errMsg; }
};

/** 
Derived from BigIntegerException class: NumberFormatException
This class is to catch exception when user initialize
a BigInteger object with an invalid-string argument, 
which does NOT contain numeric characters (0-9), or
an empty-string argument.

### You don't need to modify anything here	###
### Read and understand what it does		###
*/ 
class NumberFormatException : public BigIntegerException {
public:
	NumberFormatException(const string& err)
		: BigIntegerException(err) { }
};

#endif