#ifndef MINIARRAYQUEUE_H
#define MINIARRAYQUEUE_H
#include <iostream>     // For cout
#include "RuntimeException.h"
using namespace std;

template <class DataType>
 class miniArrayQueue {
    private:
DataType* arr;		// The array of items
int	capacity;	// The size of the current array
int	front;	// The location of the front element
int	rear;	// The location of the rear element
int queueSize;

 public:
miniArrayQueue ();	// Constructor 
miniArrayQueue(const miniArrayQueue<DataType> &); // Copy Constructor
~miniArrayQueue();	//   Destructor
int   size()   const;	// get the number of elements in the queue
bool isEmpty() const;	// Check if the queue is empty
void  enqueue(const  DataType& e); //throw(QueueFull), Enqueue element at rear
void  dequeue();     //throw(QueueEmpty), dequeue element at front 
const DataType& getFront() const ;//throw(QueueEmpty), return the front element but not remove
void  printQueue()  const;	// Prints the queue from the front to the rear
 miniArrayQueue<DataType>& operator=(const miniArrayQueue<DataType>&); // Assignment operator
};

template <class DataType>
miniArrayQueue<DataType>::miniArrayQueue()
{
    arr = new DataType[queueSize];
    capacity = 0;
    front = 0;
    rear = -1;
    queueSize = 100;
}

template <class DataType>
miniArrayQueue<DataType>::miniArrayQueue(const miniArrayQueue<DataType> &right)
{
    arr = new DataType[right.queueSize];
    front = right.front;
    rear = right.rear;
    queueSize = right.queueSize;
    capacity = right.capacity;
    for(int i = 0; i < right.queueSize; i++)
        arr[i] = right.arr[i];
}

template <class DataType>
miniArrayQueue<DataType>::~miniArrayQueue()
{
    delete[] arr;
}

template <class DataType>
int miniArrayQueue<DataType>::size() const
{
    return capacity;
}

template <class DataType>
bool miniArrayQueue<DataType>::isEmpty() const
{
    bool status = false;
    if(capacity == 0 || capacity == front)
        status = true;
    return status;
}

template <class DataType>
void miniArrayQueue<DataType>::enqueue(const DataType &e)
{
    if(capacity == queueSize)
        throw QueueFull("terminate called after throwing an instance of 'QueueFull'");
    else
    {
        rear = (rear + 1);
        arr[rear] = e;
        capacity++;
    }
}

template <class DataType>
void miniArrayQueue<DataType>::dequeue()
{
    if(isEmpty())
        throw QueueEmpty("terminate called after throwing an instance of 'QueueEmpty'");
    else
    {
        front++;
    }
}

template <class DataType>
const DataType& miniArrayQueue<DataType>::getFront() const
{
    return arr[front];
}

template <class DataType>
void miniArrayQueue<DataType>::printQueue() const
{
    for(int i = front; i < capacity; i++)
        cout << arr[i] << " ";
    cout << endl;
}

template <class DataType>
miniArrayQueue<DataType> &miniArrayQueue<DataType>::operator=(const miniArrayQueue<DataType> &right)
{
    if(this != &right)
    {
        if(this->arr)
            delete[] this->arr;
        this->capacity = right.capacity;
        this->queueSize = right.queueSize;
        this->arr = new DataType[right.queueSize];
        for(int i = 0; i < right.rear; i++)
            arr[i] = right.arr[i];
    }
    return *this; 
}



#endif