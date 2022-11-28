#ifndef LISTCOLLECTION_H
#define LISTCOLLECTION_H

#include <iostream>
#include <cstdlib>

using namespace std;

template <class T>
class ListCollection
{
  private:
    T *list;                 
    T numElements = 0;         
    T numCapacity;           
    bool isValid(T) const;  
    void resize(T);          
  public:
    ListCollection(T sz = 10);   
    ~ListCollection();            
    void setElement(T, T);     
    T getElement(T) const;     
    void displayList(bool nl = false) const;      

    ListCollection(const ListCollection &obj);
    const ListCollection operator=(const ListCollection &right);
    const ListCollection operator+(const ListCollection &right);
    const ListCollection sublist(T, T);
    const ListCollection sublist(T);
    const ListCollection sort();
    
    void clear();
    T size();
    T capacity();
    void pushFront(T);
    void pushBack(T);
    T popFront();
    T popBack();
    void insertOrdred(T);
    void removeElement(T);
    void insert(T, T);
	void remove(T);
};
template <class T>
ListCollection<T>::ListCollection(T size)
{
    list = new int[size];
    numCapacity = size;
	numElements = 0;
    for(int i = 0; i < numCapacity; i++)
        list[i] = 0;
}
template <class T>
ListCollection<T>::~ListCollection()
{
    delete[] list;
}
template <class T>
bool ListCollection<T>::isValid(T num) const
{
    bool status;
	if (num < 0 || num >= numElements - 1)
		status = false;
	else
		status = true;
	return status;
}
template <class T>
void ListCollection<T>::resize(T newSize)
{
    int *newList = new int[newSize];
	for(int i = 0; i < newSize; i++)
	{
		if(i >= numElements)
			*(newList + i) = 0;
		else if (i < numElements)
			*(newList + i) = *(list + i);
	}
	numCapacity = newSize;
	delete[] list;
	list = newList;
}
template <class T>
void ListCollection<T>::setElement(T element, T value)
{
    if (isValid(element))
		list[element] = value;
	else {
		cout << "Error: Invalid subscript\n";
		exit(EXIT_FAILURE);
	}
}
template <class T>
T ListCollection<T>::getElement(T element) const
{
    if (isValid(element))
		return list[element];
	else {
		cout << "Error: Invalid subscript: Returning 0. \n";
		return 0;
    }
}
template <class T>
void ListCollection<T>::displayList(bool nl) const
{
    for(int i = 0; i < numElements; i++)
    {
        cout << list[i] << " ";
        if(nl)
            cout << endl;
    }
    if(!nl)
        cout << endl;
}
template <class T>
ListCollection<T>::ListCollection(const ListCollection &obj)
{
    numElements = obj.numElements;
	list = new int[numElements];
	for (int i = 0; i < numElements; i++)
		list[i] = obj.list[i];
}
template <class T>
const ListCollection<T> ListCollection<T>::operator=(const ListCollection &right)
{
    delete[] list;
	numElements = right.numElements;
	list = new int[numElements];
	for (int i = 0; i < numElements; i++)
		list[i] = right.list[i];
	return *this;
}
template <class T>
const ListCollection<T> ListCollection<T>::operator+(const ListCollection &right)
{
    ListCollection newList(numElements + right.numElements);
	for(int i = 0; i < numElements; i++)
		newList.list[i] = list[i];
	for(int i = numElements, j = 0; j < right.numElements; i++, j++)
		newList.list[i] = right.list[j];
	return newList;
}
template <class T>
const ListCollection<T> ListCollection<T>::sublist(T first, T second)
{
    if(second > numElements - 1)
		second = numElements - 1;
	int newSize = second - first + 1;
	ListCollection newList(newSize);
	for(int i = 0; i < (second - first + 1); i++)
	{
		newList.list[i] = list[(i + first)];
	}
	return newList;
}
template <class T>
const ListCollection<T> ListCollection<T>::sublist(T first)
{
    int size = (numElements - first);
	ListCollection newList(size);
	for(int i = 0; i < size - 1; i++)
		newList.list[i] = 0;
	for(int i = 0; i < size ; i++)
		newList.list[i] = list[(i + first)];
	return newList;
}
/*template <class T>
 const ListCollection ListCollection<T>::sort()
{
    ListCollection newList(numElements);
	for(int i = 0; i < numElements; i++)
		newList.list[i] = list[i];
	for(int i = 0; i < numElements; i++)
	{
		for(int j = 0; j < numElements -1; j++)
		{
			if(newList[i] < newList[j])
			{
				int temp = newList[i];
				newList[i] = newList[j];
				newList[j] = temp;
			}
		}
	}
	return newList;
} */
template <class T>
void ListCollection<T>::clear()
{
    for(int i = 0; i < numCapacity; i++)
    {
        list[i] = 0;
        numElements--;
    }
}
template <class T>
T ListCollection<T>::size()
{
    return numElements;
}
template <class T>
T ListCollection<T>::capacity()
{
    return numCapacity;
}
template <class T>
void ListCollection<T>::pushFront(T num)
{
	numElements++;
	if(numElements == numCapacity)
		resize(numCapacity * 2);
	for(int i = numElements - 1; i >= 0; i--)
		list[i] = list[i - 1];
	list[0] = num;
}
template <class T>
void ListCollection<T>::pushBack(T num)
{
	if(numElements == numCapacity)
		resize(numCapacity * 2);
	list[numElements++] = num;
}
template <class T>
T ListCollection<T>::popFront()
{
    T value;
    value = list[0];
    list[0] = 0;
	for(int i = 0; i < numElements; i++)
	{
		list[i] = list[i + 1];
	}
	numElements--;
    return value;
}
template <class T>
T ListCollection<T>::popBack()
{
    int value;
    value = list[numElements - 1];
    list[numElements] = 0;
	for(int i = 0; i < numElements - 1; i++)
	{
		list[i + 1] = list[i];
	}
	numElements--;
    return value;
}
template <class T>
void ListCollection<T>::insertOrdred(T num)
{
    for(int i = 0; i < numElements; i++)
    {
        if(list[i] < num)
            list[i + 1] = num;
    }
	numElements++;
}
template <class T>
void ListCollection<T>::removeElement(T num)
{
    for(int i = 0; i < numElements; i++)
    {
        if(list[i] == num)
            list[i] = 0;
    }
	numElements--;
}
template <class T>
void ListCollection<T>::insert(T pos, T element)
{
    list[pos] = element;
}
template <class T>
void ListCollection<T>::remove(T num)
{
    list[num] = 0;
}

#endif