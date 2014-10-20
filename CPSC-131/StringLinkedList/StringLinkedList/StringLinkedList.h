#ifndef STRING_LINKED_LIST_H
#define STRING_LINKED_LIST_H

#pragma warning(disable: 4290)

#include "StringNode.h"
#include "Exception.h"

// String singly linked list
class StringLinkedList {
private:
	// pointer to the head of the list
	StringNode *head;

	// size of the list
	int n;

public:
	// default constructor
	StringLinkedList();

	// destructor 
	~StringLinkedList();

	// ## this function is provided ##
	// return the string presentation of the list
	//	example: 
	//		"A->B->C" (without quotes)
	//			A is the head node, C is the tail
	//		"" (without quotes)
	//			empty list
	std::string toString();

	// return true if the list is empty, false otherwise
	bool empty() const;

	// return the number of nodes in the list
	//	note: take advantage of the private member we have, implement this
	//		running with O(1)
	int size() const;

	// return the element of front node
	const std::string& front() const throw (EmptyException);

	// return the element of back node
	const std::string& back() const throw (EmptyException);
    
	// return the element of a node at a specific position (index) of 
	// the list
	//	EmptyException is thrown if the list is empty
	//	The index should be in range of [0, n-1]. OutOfBoundException 
	//	is thrown if index is out of that range
	const std::string& get(int index) const throw (EmptyException, OutOfBoundException);

	// add a new node with element e to the front of the list
	void addFront(const std::string& e);

	// add a new node with element e to the back of the list
	void addBack(const std::string& e);
    
	// insert a new node at a specific position (index) of the list
	//	the index should be in range of [0, n]. OutOfBoundException 
	//	is thrown if index is out of that range
	//	
	//	example: 
	//		A->B
	//			position can be inserted is 0 (before A), 1 (between
	//			A and B), 2 (after B); otherwise position will cause
	//			OutOfBoundException
	void insert(int index, const std::string& e) throw (OutOfBoundException);
    
	// remove the front node from the list
	//	EmptyException is thrown if the list is empty
	void removeFront() throw (EmptyException);

	// remove the back node from the list
	//	EmptyException is thrown if the list is empty 
	void removeBack() throw (EmptyException);

	// remove a node at a specific position (index) of the list the 
	//	index should be in range of [0, n-1]. OutOfBoundException 
	//	is thrown if index is out of that range; EmptyException is 
	//	thrown if the list is empty.
	//	
	//	example: 
	//		A->B
	//			position can be removed is 0 (A), 1 (B); otherwise 
    //          position will cause OutOfBoundException
	void remove(int index) throw (EmptyException, OutOfBoundException);

	// remove the first node that has a matched element e, starting from 
    // the head node; return true if a match is found, false otherwise
	bool remove(const std::string& e);

	// remove the ALL elements that are matched e; return true if a match 
	// is found, false otherwise
	bool removeAll(const std::string& e);

	// reverse the order of the list
	//	example: 
	//		A->B->C->D
	//			after reverse(), D->C->B->A
	void reverse();
};

#endif