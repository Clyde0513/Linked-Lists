// Set.cpp

#include "Set.h"
#include <iostream>

using namespace std;


Set::Set() {
	head = new Node;
	m_items = 0;
	head->next = head; 
	head->prev = head;
}

Set::~Set() {
	Node* p = head->next; //Points to current node
	while (p != head) { //while the current node not the dummy node (loops through the whole linked list)
		Node* aboutToBeDeleted = p->next; 
		p->next->prev = p->prev; //the current node's previous will replace the current node's previous (after its next)
		p->prev->next = p->next; //completes the circle	
		m_items--;
		delete p; //have to delete current node to avoid memory leaks.
		p = aboutToBeDeleted;
		
	}
	
	delete head; //to avoid memory leaks
}
Set::Set(const Set& other) {
	head = new Node;
	m_items = 0;
	head->next = head;
	head->prev = head;
	for (Node* p = other.head->next; p != other.head; p = p->next) {
		insert(p->value);
	}

}

Set& Set::operator=(const Set& other) {
	if (this != &other)
	{
		Set temp(other);
		swap(temp);
	}
	return *this;
}

bool Set::empty() const {
	return m_items == 0;
}

int Set::size() const {
	return m_items;
}


bool Set::insert(const ItemType& value) {
	Node* current = head->next; //points to current node
	Node* newNode = new Node; //creates new node

	if (contains(value)) { //checks if there's a value already in the list, if it is, return false
		delete newNode; //to avoid memory leaks
		return false;
	}

	while (current != head && value <= current->value) { //loops through the circular linked list and the value less than or equal to the current's value, so that it's sorted in an increasing order.
		current = current->next;
	}
	/*if (current == head) {*/
	newNode->value = value; //inserts value to the new node
	newNode->next = current; //make newNode's next arrow that of the current node.
	newNode->prev = current->prev; //make newNode's prev arrow that of the current node's prev
	newNode->next->prev = newNode; 
	newNode->prev->next = newNode; //completes the circle
	m_items++; 
	
	return true;

}

bool Set::erase(const ItemType& value) {
	Node* current = head->next; //points to current node
	if (!contains(value)) { 
		return false; 
	}

	while (current != head && value != current->value) { //goes through the circular linked list and the value has to be not equal to the current node's value
		current = current->next;
	}

	current->prev->next = current->next; //replace current's prev's next with the current's next
	current->next->prev = current->prev; //vice versa
	delete current; m_items--; return true;	//delete current to avoid leaks
}

bool Set::contains(const ItemType& value) const{
	for (Node* p = head->next; p != head; p = p->next) {
		if (value == p->value) {
			return true;
		}
	}
	return false;
}

bool Set::get(int pos, ItemType& value) const {
	if (pos < 0 || pos >= size()) { //invalid pos or pos greater than the linked list, return false
		return false;
	}

	Node* current = head->next; //points to current node
	for (int i = 0; current != head && i < pos; i++, current = current->next) { //iterate through the element up to position; link from first node to 2nd node ... 
		; //i has to be less than pos so that it gets the value at the end
	}
	value = current->value; //gets the value
	return true;

	
}

void Set::swap(Set& other) {
	int item_Swap = other.m_items;
	other.m_items = m_items;
	m_items = item_Swap;

	Node* swapSets = other.head;
	other.head = head;
	head = swapSets;
}


void unite(const Set& s1, const Set& s2, Set& result) {

	Set temp;
	for (int i = 0; i < s1.size(); i++) {
		/*iterates through the size of s1 set
		creates a temp ItemType so that I can put s1 elements in s1 using insert*/
		ItemType j;
		s1.get(i, j);
		temp.insert(j);
	}


	for (int i = 0; i < s2.size(); i++) {
		/*same idea as above*/
		ItemType j;
		s2.get(i, j);
		temp.insert(j);
	}
	/*if (&s1 == &result || &s2 == &result) {
		result = s1;
	}*/
	result.swap(temp);
}

void butNot(const Set& s1, const Set& s2, Set& result) {
	Set temp = s1; //copy s1 elements to temp to be used in the loop
	for (int i = 0; i < s1.size(); i++) {
		/*creates ItemType
		so that I can use it to see if s2 elements contains that of s1 elements, 
		if it is, use erase, so that only s1 elements will be included (no duplicates) and no intersection of both sets*/
		ItemType value;
		s1.get(i, value);
		if (s2.contains(value)) {
			temp.erase(value);
		}
	}
	
	result.swap(temp);
	
}
/*prints information about the linked list data*/
void Set::dump() const {
	cerr << "The size of the Set is: " << size()  << endl;
	cerr << "The items in the Set are: " << endl;
	Node* current = head->next;
	for (; current != head; current = current->next) {
		cerr << current->value << " ";
	}
	cerr << endl;
}