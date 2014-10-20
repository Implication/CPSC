#include "GenericDLList.h"
#include <sstream>

// constructor
template <typename ElemType>
GenericDLList<ElemType>::GenericDLList() {
	// initialize header and trailer
	header = new GenericDNode<ElemType>();
	trailer = new GenericDNode<ElemType>();
	header->next = trailer;
	trailer->prev = header;

	// size
	n = 0;
}

// destructor (INCOMPLETE)
template <typename ElemType>
GenericDLList<ElemType>::~GenericDLList() {

}

// ## this function is provided ##
// return the string presentation of the list by following next pointers
//	example: 
//		"1<->2<->3"
//			1 is the front node, 3 is the back node
//			output: "1->2->3" (without quotes)
//		""
//			empty list
//			output: "" (without quotes)
template <typename ElemType>
std::string GenericDLList<ElemType>::nextDirString() {
	// special case: empty list
	if (header->next == trailer) return "";

	// initialize output string stream
	std::ostringstream oss("");

	// traverse each node to the back and append element of each node
	GenericDNode<ElemType> *node = header->next;
	while (node != trailer) {
		oss << node->elem << "->";
		node = node->next;
	}

	// convert to string 
	std::string output = oss.str();
	// remove last 2 characters
	return output.substr(0, output.size() - 2);
}

// ## this function is provided ##
// return the string presentation of the list by following prev pointers
//	example: 
//		"1<->2<->3"
//			1 is the front node, 3 is the back node
//			output: "1<-2<-3" (without quotes)
//		"" (without quotes)
//			empty list
//			output: "" (without quotes)
template <typename ElemType>
std::string GenericDLList<ElemType>::prevDirString() {
	// special case: empty list
	if (trailer->prev == header) return "";

	// initialize output string stream
	std::ostringstream oss("");

	// traverse each node to the back and append element of each node
	GenericDNode<ElemType> *node = trailer->prev;
	while (node != header) {
		oss << node->elem << "-<";
		node = node->prev;
	}

	// convert to string
	std::string output = oss.str();
	// reverse string and remove last 2 characters
	return std::string(output.rbegin() + 2, output.rend());
}