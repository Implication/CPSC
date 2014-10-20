#ifndef STRING_NODE_H
#define STRING_NODE_H

#include <string>

// A node in string singly linked list
class StringNode {
private:
	// element value of a node
	std::string elem;
	
	// pointer to the next node in the list
	StringNode *next;
	
	// provide StringLinkedList access
	friend class StringLinkedList;
};

#endif