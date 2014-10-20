#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <string>

/*
### You don't need to modify anything here	###
### Read and understand what it does		###

RuntimeException: base class
This class is to catch all exceptions related to
StringLinkedList class
*/

class RuntimeException {
private:
	std::string errMsg;

public:
	RuntimeException(const std::string& err)
		: errMsg(err) { }
	std::string getMessage() const { return errMsg; }
};

/*
Derived from RuntimeException class: EmptyException

This class is to catch exception when user call any function to read 
or modify an element from a head node when the list is empty
*/
class EmptyException : public RuntimeException {
public:
	EmptyException(const std::string& err)
		: RuntimeException(err) { }
};

/*
Derived from RuntimeException class: OutOfBoundException

This class is to catch exception when user call any function to read or
modify a node in a list using index or modifying position.
*/
class OutOfBoundException : public RuntimeException {
public:
	OutOfBoundException(const std::string& err)
		: RuntimeException(err) { }
};

#endif