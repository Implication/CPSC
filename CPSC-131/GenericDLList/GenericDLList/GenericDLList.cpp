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
	if (!empty()) removeFront();
	delete header;
	delete trailer;
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

template <typename ElemType>
bool GenericDLList<ElemType>::empty() const{
	return header->next == trailer;
}

template <typename ElemType>
int GenericDLList<ElemType>::size() const{
	return n;
}

template <typename ElemType>
const ElemType& GenericDLList<ElemType>::front() const {
	if (empty()){
		throw EmptyException("Empty List");
	}
	return header->next->elem;
}

template <typename ElemType>
void GenericDLList<ElemType>::add(GenericDNode<ElemType> *aNode, const ElemType& e){
	GenericDNode<ElemType>* u = new GenericDNode<ElemType>;
	u->elem = e;
	u->next = aNode;
	u->prev = aNode->prev;
	aNode->prev->next = u;
	aNode->prev = u;
	n++;
}

template <typename ElemType>
const ElemType& GenericDLList<ElemType>::back() const {
	if (empty()){
		throw EmptyException("Empty List");
	}
	return trailer->prev->elem;
}

template <typename ElemType>
void GenericDLList<ElemType>::addFront(const ElemType& e){
	add(header->next, e);
}

template <typename ElemType>
void GenericDLList<ElemType>::addBack(const ElemType& e){
	add(trailer, e);
}

template <typename ElemType>
void GenericDLList<ElemType>::remove(GenericDNode<ElemType> *aNode){
	GenericDNode<ElemType>* u = aNode->prev;
	GenericDNode<ElemType>* w = aNode->next;
	u->next = w;
	w->prev = u;
	delete aNode;
	n--;
}

template <typename ElemType>
void GenericDLList<ElemType>::removeFront(){
	if (empty()){
		throw EmptyException("Empty List");
	}
	remove(header->next);
}

template <typename ElemType>
void GenericDLList<ElemType>::removeBack(){
	if (empty()){
		throw EmptyException("Empty List");
	}
	remove(trailer->prev);
}

template <typename ElemType>
const ElemType& GenericDLList<ElemType>::get(int index) const {
	if (empty()){
		throw EmptyException("Empty List");
	}

	if(index < 0 || index > n-1)
		throw OutOfBoundException("Index is out of bounds.");
	
		if (index == 0) return front();
		else if (index == n-1) return back();
		else{
			GenericDNode<ElemType>* u = header->next->next;
			int pos = 1;
			while (pos != index){
				u = u->next;
				pos++;
			}
			return u->elem;
		}
}
template <typename ElemType>
void GenericDLList<ElemType>::insert(int pos, const ElemType& e){
	if (pos < 0 || pos > n){
		throw OutOfBoundException("Out of bounds");
	}

	if (pos <= n / 2){
		GenericDNode<ElemType>* node = header;
		for (int i = 0; i <= pos; ++i)
			node = node->next;
		add(node, e);
	}
	else{
		GenericDNode<ElemType>* node = trailer;
		for (int i = 0; i < n - pos; ++i)
			node = node->prev;
		add(node, e);
	}
}

template <typename ElemType>
void GenericDLList<ElemType>::remove(int index){
	if (empty()){
		throw EmptyException("Empty List");
	}

	if (index < 0 || index > n - 1){
		throw OutOfBoundException("Index Out Of Bounds");
	}

	

	if (index == 0)
		(remove(header->next));
	else if (index == n - 1)
		(remove(trailer->prev));
	else{
		GenericDNode<ElemType>* node = header->next;
		for (int i = 0; i <= index - 1; i++)
			node = node->next;
		remove(node);
	}
}

template <typename ElemType>
bool GenericDLList<ElemType>::remove(const ElemType& e){
	bool found = false;
	if (empty()){
		return found;
	}

	GenericDNode<ElemType>* node = header;
	while (node->next != NULL && node->elem != e){
		node = node->next;
	}

	if (node->elem == e){
		remove(node);
		found = true;
	}
	else{
		found = false;
	}
	
	return found;
}

template <typename ElemType>
bool GenericDLList<ElemType>::removeAll(const ElemType& e){
	bool found = false;
	if (empty()){
		return found;
	}

	GenericDNode<ElemType>* node = header;
	while (node->next != NULL){
		if (node->elem == e){
			GenericDNode<ElemType>* match = node;
			node = node->next;
			remove(match);
			found = true;
		}
		else{
			node = node->next;
		}
	}

	if (node->elem == e){
		remove(node);
		found = true;
	}
	else{
		found = false;
	}
	return found;
}

template <typename ElemType>
void GenericDLList<ElemType>::reverse(){
		GenericDNode<ElemType>* u = header->next;
		int size = n;
		for (int i = 0; i < size; ++i){
			addFront(u->elem);
			u = u->next;
		}
		for (int i = 0; i < size; ++i){
			removeBack();
		}

}

//Need to see teacher about reversing on DLL, no formulas work because it includes a trailer.

