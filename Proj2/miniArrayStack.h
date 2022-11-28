#ifndef MINIARRAYSTACK_H
#define MINIARRAYSTACK_H
#include <iostream>     // For cout
#include "RuntimeException.h"
using namespace std;


template <class DataType>
 class miniArrayStack{
private:
enum {DEF_CAPACITY = 100}; 	//default stack capacity
DataType* arr;	// The array of items
int	capacity;	// The size of the current array
int	top;	// The location of the top element
int stackSize;
 

 public:
 miniArrayStack (int cap= DEF_CAPACITY);	// Constructor for ArrStack
miniArrayStack(const miniArrayStack<DataType> &); 	// Copy contstructor
~miniArrayStack();	// Destructor
int  size()  const;	// get the number of elements in the stack
bool isEmpty() const;	// Check if the stack is empty
const DataType& getTop() const; //throw(StackEmpty);       //get the top emement without popping it
void push(const DataType&); //throw(StackFull);	// Pushes  an  object  onto  the  stack
void pop() ;//throw(StackEmpty);	// Pop an object off the stack 
 void  printStack()  const;	// Prints the stack from the top, down
miniArrayStack<DataType>& operator=(const miniArrayStack<DataType>&);  //  Assignment  operator
};

template <class DataType>
miniArrayStack<DataType>::miniArrayStack(int cap)
{
    arr = new DataType[cap];
    stackSize = cap;
    top = -1;
    capacity = 0;
}

template <class DataType>
miniArrayStack<DataType>::~miniArrayStack()
{
    delete[] arr;
}

template <class DataType>
miniArrayStack<DataType>::miniArrayStack(const miniArrayStack<DataType> &right)
{
    if(right.stackSize > 0)
        arr = new DataType[right.stackSize];
    else
        arr = nullptr;
    stackSize = right.stackSize;
    for(int i = 0; i < stackSize; i++)
        arr[i] = right.arr[i];
    top = right.top;
}

template <class DataType>
int miniArrayStack<DataType>::size() const
{
    int size = capacity;
    return size;
}

template <class DataType>
bool miniArrayStack<DataType>::isEmpty() const
{
    bool status = false;
    if(top == -1)
        status = true;
    return false;
}

template <class DataType>
const DataType& miniArrayStack<DataType>::getTop() const
{
    if(isEmpty())
        throw StackEmpty("terminate called after throwing an instance of 'StackEmpty'");
    else
        return arr[top];
}

template <class DataType>
void miniArrayStack<DataType>::push(const DataType &num)
{
    if(top < stackSize)
    {
        top++;
        arr[top] = num;
        capacity++;
    }
    else
        throw StackFull("terminate called after throwing an instance of 'StackFull'");
}

template <class DataType>
void miniArrayStack<DataType>::pop()
{
    if(isEmpty())
        throw StackEmpty("terminate called after throwing an instance of 'StackEmpty'");
    else
    {
        //num = arr[top];
        top--;
        capacity--;
    }
}

template <class DataType>
void miniArrayStack<DataType>::printStack() const
{
    for(int i = capacity - 1; i > -1; i--)
        cout << arr[i] << " ";
    cout << endl;
}

template <class DataType>
miniArrayStack<DataType> &miniArrayStack<DataType>::operator=(const miniArrayStack<DataType> &right)
{
    if(&right != this)
    {
        delete[] arr;
        stackSize = right.stackSize;
        arr = new DataType[stackSize];
        top = right.top;
        for(int i = 0; i < top; i++)
            arr[i] = right.arr[i];
    }
    return *this;
}


#endif