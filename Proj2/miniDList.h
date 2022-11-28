#ifndef MINIDLIST_H
#define MINIDLIST_H
#include <iostream>     // For cout
using namespace std;


template <class DataType> 
class miniDList
{
protected:
struct   DNode{	// doubly linked list node
  DataType data;	//  data stored in node   
  struct DNode*   next;	//  next node in list   
  struct DNode*   prev;	//  previous node  in list
};

 DNode* header;	// list sentinels
 DNode* trailer;	
public:
miniDList()
{                      // constructor
header = new DNode;
trailer  = new DNode;         //have them point to each other
header->next = trailer;
trailer->prev = header;
}	
miniDList(const   miniDList<DataType>&  l);  // Copy constructor
~miniDList();	// Destructor
const DataType& front() const;      // get front element
const DataType& back() const;       // get back element
void   removeFront();	// Remove the front 
void   removeBack();             // Remove the back 
void addFront(const DataType& e);       // Add to the front 
void addBack(const DataType& e);           // Add to the back
int   size()   const;	// Returns the number of elements in list
bool contains(const DataType& e);   // Tests for membership
void  display()  const;	// Prints the elements of list
miniDList<DataType>& operator=(const miniDList<DataType>& l);   //Overloaded assignment

protected:                          //local utilities
void add(DNode * v, const DataType& e); //insert new node  before  v
void remove(DNode* v);     //remove node v
};

template <class DataType>
miniDList<DataType> &miniDList<DataType>::operator=(const miniDList<DataType> &l)
{
  DNode *nodePtr = l.header;
  while(nodePtr != nullptr)
  {
    addBack(nodePtr->data);
    nodePtr = nodePtr->next;
  }
  return *this;
}

template <class DataType>
miniDList<DataType>::miniDList(const miniDList<DataType> &l)
{
  DNode *nodePtr = l->header->next;
  while(nodePtr != l->trailer)
    addFront(nodePtr->data);
}

template <class DataType>
miniDList<DataType>::~miniDList()
{
  DNode *nodePtr = header;
  while(nodePtr != nullptr)
  {
    removeBack();
  }
}

template <class DataType>
const DataType& miniDList<DataType>::front() const
{
  return header->next->data;
}

template <class DataType>
const DataType& miniDList<DataType>::back() const
{
  return trailer->prev->data;
}

template <class DataType>
void miniDList<DataType>::removeFront()
{
 remove(header->next);
}

template <class DataType>
void miniDList<DataType>::removeBack()
{
  remove(trailer->prev);
}

template <class DataType>
void miniDList<DataType>::addFront(const DataType &e)
{
  DNode *newNode = new DNode;
  DNode *nextNode = header->next;
  newNode->data = e;
  nextNode ->prev = newNode;
  newNode->next = nextNode;
  newNode->prev = header;
  header->next = newNode;
}

template <class DataType>
void miniDList<DataType>::addBack(const DataType &e)
{
  DNode *newNode = new DNode;
  DNode *nodePtr = trailer->prev;
  newNode->data = e;
  trailer->prev->next = newNode;
  newNode->prev = nodePtr;
  newNode->next = trailer;
  trailer->prev = newNode;
}

template <class DataType>
int miniDList<DataType>::size() const
{
  cout << endl;
  DNode *nodePtr = header;
  nodePtr = header;
  int value = 0;
  while(nodePtr->next != trailer)
  {
    value++;
    nodePtr = nodePtr->next;
  }
  return value;
}

template <class DataType>
bool miniDList<DataType>::contains(const DataType &e)
{
  DNode *nodePtr = header;
  bool status = false;
  while(nodePtr != nullptr)
  {
    if(nodePtr->data == e)
      {
        status = true;
        return status;
      }
    nodePtr = nodePtr->next;
  }
  return status;
}

template <class DataType>
void miniDList<DataType>::display() const
{
  DNode *nodePtr = new DNode;
  nodePtr = header;
  while(nodePtr->next != trailer)
  {
    nodePtr = nodePtr->next;
    cout << nodePtr->data << " ";
  }
}

template <class DataType>
void miniDList<DataType>::add(DNode *v, const DataType &e)
{
  DNode *newNode = new DNode;
  newNode->data = e;
  newNode->prev = v->prev;
  newNode->next = v;
  v->prev = newNode;
}

template <class DataType>
void miniDList<DataType>::remove(DNode *v)
{
  v->prev->next = v->next;
  v->next->prev = v->prev;
  delete v;
}

#endif