#ifndef LISTCOLLECTION_H
#define LISTCOLLECTION_H

#include <iostream>
#include <cstdlib>

using namespace std;

template<class T>
class ListCollection {
private:
	struct ListNode
	{
		T value;
		struct ListNode *next;
	};
	ListNode *head; //Gotta find some head
	bool isValid(int);

public:
	ListCollection(int sz = 10);
	~ListCollection();
	void setElement(int, T);
	T getElement(int);
	void displayList(bool nl = false) const;

	ListCollection(const ListCollection &obj);
	const ListCollection<T> operator=(const ListCollection &right);

	const ListCollection<T> operator+(const ListCollection &right);
	const ListCollection<T> sublist(int, int);
	const ListCollection<T> sublist(int);
	const ListCollection<T> sort();

	void clear();
	int size();
	int capacity();
	void pushFront(T);
	void pushBack(T);
	T popFront();
	T popBack();
	void insertOrdred(T);
	void removeElement(T);
	void insert(int, T);
	void remove(int);
};

template<class T>
ListCollection<T>::ListCollection(int size) {
	head = nullptr;
}

template<class T>
ListCollection<T>::~ListCollection() {
	ListNode *nodePtr;
	ListNode *nextNode;
	nodePtr = head;
	while(nodePtr != nullptr)
	{
		nextNode = nodePtr->next;
		delete nodePtr;
		nodePtr = nextNode;
	}
}

template<class T>
ListCollection<T>::ListCollection(const ListCollection &obj) {
	ListNode *nodePtr = obj.head;
	while(nodePtr)
	{
		pushBack(nodePtr->value);
		nodePtr = nodePtr->next;
	}
}

template<class T>
const ListCollection<T> ListCollection<T>::operator=(const ListCollection &right) {
	ListNode *nodePtr = right.head;
	while(nodePtr)
	{
		pushBack(nodePtr->value);
		nodePtr = nodePtr->next;
	}
	return *this;
}

template<class T>
bool ListCollection<T>::isValid(int element) {
	bool status;
	int value = size();

	if (element < 0 || element >= value)
		status = false;
	else
		status = true;

	return status;
}

template<class T>
void ListCollection<T>::setElement(int element, T num) {
	ListNode *newNode = new ListNode;
	ListNode *nodePtr;
	newNode->value = num;
	newNode->next = nullptr;
	if(!head) //So no head?
		head = newNode;
	else
	{
		nodePtr = head;
		for(int i = 0; i < element; i++)
			nodePtr = nodePtr->next;
		nodePtr->next = newNode;
	}
}

template<class T>
T ListCollection<T>::getElement(int pos) {
	T num;
	ListNode *nodePtr = head;
	ListNode *newNode;
	if(!head)
		return num;
	else
	{
		for(int i = 0; i < pos; i++)
			nodePtr = nodePtr->next;
		num = nodePtr->value;
	}
	return num;
}

template<class T>
void ListCollection<T>::displayList(bool nl) const {
	ListNode *nodePtr = head;
	while(nodePtr)
	{
		cout << nodePtr->value << " ";
		nodePtr = nodePtr->next; 
	}
	cout << endl;
}

template<class T>
const ListCollection<T> ListCollection<T>::operator+(const ListCollection &right) {
	ListCollection<T> *nodeResult = new ListCollection;
	*nodeResult = *this;
	*nodeResult += right;
	return nodeResult;
}

template<class T>
const ListCollection<T> ListCollection<T>::sublist(int b, int e) {
	 if (b > e) {
		int temp = b;
		b = e;
		e = temp;
	}

	if (b < 0)
		b = 0;

	if (e < 0)
		e = 0;

	if (b >= size())
		b = size() - 1;

	if (e >= size())
		e = size() - 1;

	ListCollection<T> newList;
	ListNode *nodePtr = head;
	for(int i = 0; i < e - b; i++)
	{
		for(int j = 0; j < b - i; j++)
			nodePtr->next;
		newList.pushBack(nodePtr->value);
	}
	return newList;
}

template<class T>
const ListCollection<T> ListCollection<T>::sublist(int b) {
	return sublist(b, size() - 1);
}

template<class T>
const ListCollection<T> ListCollection<T>::sort() {
	ListCollection<T> newList;
	ListNode *nodePtr = head;
	/* for(int i = 0; i < size(); i++)
	{
		newList.pushFront(nodePtr->value);
		nodePtr = nodePtr->next;
	}
	ListNode *newNode = newList.head;
	nodePtr = newList.head;
	nodePtr = nodePtr->next;
	for(int i = 0; i < size(); i++)
	{
		for(int j = 0; j < size() - 1 - i; j++)
		{
			if(nodePtr->value < newNode->value)
			{
				T temp = nodePtr->value;
				nodePtr->value = newNode->value;
				newNode->value = temp;
			}
			nodePtr = nodePtr->next;
			newNode = newNode->next;
		}
		newNode = head;
		nodePtr = head->next;
	} */
	while(nodePtr)
	{
		newList.insertOrdred(nodePtr->value);
		nodePtr = nodePtr->next;
	}
	return newList;
}

template<class T>
int ListCollection<T>::size() {
	int numNodes = 0;
	ListNode *nodePtr;
	nodePtr = head;
	while(nodePtr)
	{
		numNodes++;
		nodePtr = nodePtr->next;
	}
	return numNodes;
}

template<class T>
int ListCollection<T>::capacity() {
	return size();
}

template<class T>
void ListCollection<T>::pushFront(T elt) {
	ListNode *newNode = new ListNode;
	newNode->value = elt;
	if(!head)
		head = newNode;
	else
	{
		newNode->next = head;
		head = newNode;
	}
}

template<class T>
void ListCollection<T>::pushBack(T elt) {
	ListNode *nodePtr = head;
	ListNode *newNode;
	newNode = new ListNode;
	newNode->value = elt;
	if(!head)
		head = newNode;
	while(nodePtr->next)
		nodePtr = nodePtr->next;
	nodePtr->next = newNode;
}

template<class T>
T ListCollection<T>::popFront() {
	T defaultret;
	ListNode *nodePtr = head;

	if(!head) //So no head?
		return defaultret;
	T num = head->value;
	head = nodePtr->next;
	delete nodePtr;
	return num;
}

template<class T>
T ListCollection<T>::popBack() {
	T num;
	ListNode *nodePtr = head;
	ListNode *previousNode = nullptr;
	if(!head) //So no head?
		return num;
	while(nodePtr->next)
	{
		previousNode = nodePtr;
		nodePtr = nodePtr->next;
	}
	T newNum = nodePtr->value;
	if(previousNode)
		previousNode->next = nullptr;
	else
		head = nullptr;
	delete nodePtr;
	return newNum;
}

template<class T>
void ListCollection<T>::insertOrdred(T elt) {
   ListNode *newNode = new ListNode;
   ListNode *nodePtr = head;
   ListNode *previousNode = nullptr;
   if (!head)
      head = newNode;
   else  
   {
      while(nodePtr && nodePtr->value < elt)
	  {
		previousNode = nodePtr;
		nodePtr = nodePtr->next;
	  }
	  newNode->next = nodePtr;
	  if(!previousNode)
	  	head = newNode;
	else
		previousNode->next = newNode;
   }
}

template<class T>
void ListCollection<T>::removeElement(T elt) {
	ListNode *nodePtr;
	ListNode *previousNode;
	if (!isValid(elt))
		return;
	if(head->value == elt)
	{
		nodePtr = head->next;
		delete head;
		head = nodePtr;
	}
	else
	{
		nodePtr = head;
		while(nodePtr != nullptr && nodePtr->value != elt)
		{
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}
		if(nodePtr)
		{
			previousNode->next = nodePtr->next;
			delete nodePtr;
		}
	}
}

template<class T>
void ListCollection<T>::insert(int pos, T elt) {
	ListNode *nodePtr = head;
	ListNode *previousNode = head;
	if (pos >= size())
		pushBack(elt);
	else if (pos <= 0)
		pushFront(elt);
	else {
		insertOrdred(elt);
	}
}

template<class T>
void ListCollection<T>::remove(int pos) {
	ListNode *nodePtr = head;
	ListNode *previousNode = head;
	if(!head)
		return;
	for(int i = 0; i < pos; i++)
		nodePtr->next;
	for(int i = 0; i < pos - 1; i++)
		previousNode->next;
	previousNode->next = nodePtr;
	delete nodePtr;
}

template<class T>
void ListCollection<T>::clear() {
	head = nullptr; //nonexistent head
}

#endif
