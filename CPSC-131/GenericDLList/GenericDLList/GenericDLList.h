#ifndef GENERIC_D_L_LIST_H
#define GENERIC_D_L_LIST_H

#pragma warning(disable: 4290)

#include "Exception.h"

template <typename ElemType>
class GenericDLList;

template <typename ElemType>
class GenericDNode {
private:
	// element value of a node
	ElemType elem;

	// pointer to the previous node in the list
	GenericDNode<ElemType> *prev;

	// pointer to the next node in the list
	GenericDNode<ElemType> *next;

	friend class GenericDLList<ElemType>;

public:
	GenericDNode()
		: elem(ElemType()), prev(NULL), next(NULL) { }

	~GenericDNode() { }
};

// Generic double linked list of type ElemType
template <typename ElemType>
class GenericDLList {
private:
	// pointer to the head of the list
	GenericDNode<ElemType> *header;
	GenericDNode<ElemType> *trailer;

	int n;

	// addition functions ...
	// add a new node with elem e after aNode
	void add(GenericDNode<ElemType> *aNode, const ElemType& e);

	// remove a node after aNode
	void remove(GenericDNode<ElemType> *aNode);

public:
	// default constructor
	GenericDLList();

	// destructor 
	~GenericDLList();

	// ## this function is provided ##
	// return the string presentation of the list by following next pointers
	//	example: 
	//		"1<->2<->3"
	//			1 is the front node, 3 is the back node
	//			output: "1->2->3" (without quotes)
	//		""
	//			empty list
	//			output: "" (without quotes)
	std::string nextDirString();

	// ## this function is provided ##
	// return the string presentation of the list by following prev pointers
	//	example: 
	//		"1<->2<->3"
	//			1 is the front node, 3 is the back node
	//			output: "1<-2<-3" (without quotes)
	//		"" (without quotes)
	//			empty list
	//			output: "" (without quotes)
	std::string prevDirString();

	// return true if the list is empty, false otherwise
	bool empty() const;

	// return the number of nodes in the list
	//	note: take advantage of the private member we have, implement this
	//		running with O(1)
	int size() const;

	// return the element of front node
	const ElemType& front() const throw (EmptyException);

	// return the element of back node
	const ElemType& back() const throw (EmptyException);

	// add a new node with element e to the front of the list
	void addFront(const ElemType& e);

	// remove the front node from the list
	//	EmptyException is thrown if the list is empty
	void removeFront() throw (EmptyException);

	// add a new node with element e to the back of the list
	void addBack(const ElemType& e);

	// remove the back node from the list
	//	EmptyException is thrown if the list is empty 
	void removeBack() throw (EmptyException);

	// return the element of a node at a specific position (index) of 
	// the list
	//	EmptyException is thrown if the list is empty
	//	The index should be in range of [0, n-1]. OutOfBoundException 
	//	is thrown if index is out of that range
	const ElemType& get(int index) const throw (EmptyException, OutOfBoundException);

	// insert a new node at a specific position (index) of the list
	//	the index should be in range of [0, n]. OutOfBoundException 
	//	is thrown if index is out of that range
	//	
	//	example: 
	//		A<->B
	//			position can be inserted is 0 (before A), 1 (between
	//			A and B), 2 (after B); otherwise position will cause
	//			OutOfBoundException
	void insert(int pos, const ElemType& e) throw (OutOfBoundException);

	// remove a node at a specific position (index) of the list the 
	//	index should be in range of [0, n-1]. OutOfBoundException 
	//	is thrown if index is out of that range; EmptyException is 
	//	thrown if the list is empty.
	//	
	//	example: 
	//		A<->B
	//			position can be removed is 0 (A), 1 (B); otherwise position will cause
	//			OutOfBoundException
	void remove(int index) throw (EmptyException, OutOfBoundException);

	// remove the first element that is matched e, starting from the head
	// node; return true if a match is found, false otherwise
	bool remove(const ElemType& e);

	// remove the ALL elements that are matched e; return true if a match 
	// is found, false otherwise
	bool removeAll(const ElemType& e);

	// reverse the order of the list
	//	example: 
	//		A<->B<->C<->D
	//			after reverse(), D<->C<->B<->A
	void reverse();
};

#endif