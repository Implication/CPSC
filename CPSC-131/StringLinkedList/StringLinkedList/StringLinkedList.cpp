#include "StringLinkedList.h"

StringLinkedList::StringLinkedList() //default constructor
	: head(NULL), n(0) { }

StringLinkedList::~StringLinkedList() { //deconstructor to delete all the elements after creating them 
	if (head != NULL){
		StringNode* node  = head;
		while (node != NULL){
			StringNode* e = node->next;
			delete node;
			node = e;
		}
	}
}


bool StringLinkedList::empty() const{ //Empty check
	return head == NULL;
}

int StringLinkedList::size() const{ //Returns the size of the list
	return n;
}

void StringLinkedList::addFront(const std::string& e){ 
	StringNode* v = new StringNode; //Set a new string node
	v->elem = e; //Set that new string node's element equal to the given elemetn
	v->next = head; //Set the new elemetns next's elemetn equal to the original head
	head = v; //Head is now the new elemetn
	n++;
}
std::string StringLinkedList::toString() {
	if (head == NULL)         return "";
	std::string out = "";
	StringNode *node = head;
	while (node != NULL) {
		out += node->elem + "->";
		node = node->next;
	}
	return out.substr(0, out.size()-2);
}

const std::string& StringLinkedList::front() const{
	if (empty()){ //Empty list check
		throw EmptyException("Empty list");
	}
	else{ //Prints the front element
		return head->elem;
	}
}

const std::string& StringLinkedList::back() const {
	if (empty()){ //Empty list check
		throw EmptyException("Empty list");
	}
	else{
		StringNode* back = head;
		while (back->next != NULL){ //Transverse through the list
			back = back->next;
		}
		return back->elem; //Returns the last element
	}
}

const std::string& StringLinkedList::get(int index) const {
	if (empty()){ //empty list
		throw EmptyException("Empty list");
	}
	if (index > n - 1 || index < 0){ //If the index is bigger than the size of the linked list or if the index is smaller than 0 then it is out of range
		throw OutOfBoundException("Index is Out of Bounds");
	}

	StringNode* v = head; int pos = 0; //Look for the element 
	while (pos != index){
		v = v->next;
		pos++;
	}
	return v->elem;
}

void StringLinkedList::addBack(const std::string& e) {
	StringNode* v = new StringNode;
	v->elem = e;
	v->next = NULL;
	if (empty()){
		head = v;
		n++;
	}
	else{
		StringNode* node = head;
		while (node->next != NULL){
			node = node->next;
		}
		node->next = v;
		n++;
	}
}

void StringLinkedList::insert(int index, const std::string& e) {
	if (index < 0 || index > n){
		throw OutOfBoundException("index is out of bounds");
	}
	
	else
{
		StringNode* node = head, *prev = new StringNode;
		StringNode* v = new StringNode;
		v->elem = e;
		int pos = 0;
		while (pos != index  && node-> next != NULL){
			prev = node;
			node = node->next;
			pos++;
		}
		if(index == 0) addFront(e);
		else if(index == n) addBack(e);
		else{
		prev->next = v;
		v->next = node;
		n++;
		}
	}
}

void StringLinkedList::remove(int index) {
	if (empty()){
		throw EmptyException("Empty list");
	}
	
	if (index < 0 || index > n - 1){
		throw OutOfBoundException("Index is out of bounds");
	}

	else{
		StringNode* remove = head, *prev = head;
		int pos = 0;
		while (pos != index && remove->next != NULL){
			prev = remove;
			remove = remove->next;
			pos++;
		}
		if (index == 0){ removeFront(); }
		else if(index == n) { removeBack(); }
		else{
			prev->next = remove->next;
			delete remove;
			n--;
		}
		
	
	}
}

bool StringLinkedList::remove(const std::string& e) {
	bool found = false;
	if (empty()){ //Empty list
		found = false;
	}
	else if (head->elem == e && head->next == NULL){
	removeFront();
	head = NULL;
	found = true;
	}
	else if (head->elem == e && head->next != NULL){
		removeFront();
		found = true;
	}
	else{
		StringNode* node = head->next, *prev = head;
		while (head->next != NULL){
			while (node->next != NULL && node->elem != e){
				prev = node;
				node = node->next;
			}
			if (node->elem == e){
				prev->next = node->next;
				delete node;
				found = true;
				n--;
				break;
			}
			else {
				break;
			}
		}
	}
	return found;
}
void StringLinkedList::removeFront() {
	if (empty()){ //Empty list
		throw EmptyException{ "Empty list" };
	}
	else{
		StringNode* tmp = head->next;
		delete head;
		head = tmp;
		n--;
	}
}


void StringLinkedList::removeBack() {
	if (empty()){ //Empty list condition
		throw EmptyException("Empty List");
	}

	if (head->next == NULL){ //Only one element in the list
		delete head;
		head = NULL;
		n--;
	}

	else{ //Multiple elemetn in the string
		StringNode* node = head->next, *prev = head; //sets a node equal to the next element, and  a prev equal to the first elemetn
		while (node->next != NULL){ //tranverse through the list
			prev = node;
			node = node->next;
		}
		prev->next = NULL; //Set the element before node's pointer to the next elemetn equal to null
		delete node; //delete the pointer
	}
}

bool StringLinkedList::removeAll(const std::string& e) {
	bool found = false; //Checks to see if the elemtn is found
	if (empty()){ //Condition if the bool is empty
		return false;
	}
	while (head != NULL && head->elem == e){
		StringNode* old = head;
		head = head->next;
		delete old;
		n--;
	}
	if (head != NULL){
		StringNode* node = head->next, *prev = head;
		while (node->next != NULL){
			if (node->elem == e){
				StringNode* match = node;
				prev->next = node->next;
				node = node->next;
				delete match;
				n--;
			}
			else{
				prev = node;
				node = node->next;
			}
		}
		if (node->elem == e){
			prev->next = node->next;
			delete node;
			n--;
		}
	}
}

void StringLinkedList::reverse(){
	// Create a pointer to StringNode* equal to a new stringNode object
		StringNode* prev = NULL, *node;
		while (head){
			node = head->next;
			head->next = prev;
			prev = head;
			head = node;
		}
		head = prev;
	}
