#include "List.h"
#include <iostream>

using namespace std;

ListCollection::ListCollection(int size)
{
    list = new int[size];
    numCapacity = size;
	numElements = 0;
    for(int i = 0; i < numCapacity; i++)
        list[i] = 0;
}
ListCollection::~ListCollection()
{
    delete[] list;
}
bool ListCollection::isValid(int num) const
{
    bool status;
	if (num < 0 || num >= numElements)
		status = false;
	else
		status = true;
	return status;
}
void ListCollection::resize(int newSize)
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
void ListCollection::setElement(int element, int value)
{
    if (isValid(element))
		list[element] = value;
	else {
		cout << "Error: Invalid subscript\n";
		exit(EXIT_FAILURE);
	}
}
int ListCollection::getElement(int element) const
{
    if (isValid(element))
		return list[element];
	else {
		cout << "Error: Invalid subscript: Returning 0. \n";
		return 0;
    }
}
void ListCollection::displayList(bool nl) const
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
ListCollection::ListCollection(const ListCollection &obj)
{
    numElements = obj.numElements;
	list = new int[numElements];
	for (int i = 0; i < numElements; i++)
		list[i] = obj.list[i];
}
const ListCollection ListCollection::operator=(const ListCollection &right)
{
    delete[] list;
	numElements = right.numElements;
	list = new int[numElements];
	for (int i = 0; i < numElements; i++)
		list[i] = right.list[i];
	return *this;
}
const ListCollection ListCollection::operator+(const ListCollection &right)
{
    ListCollection newList(numElements + right.numElements);
	for(int i = 0; i < numElements; i++)
		newList.list[i] = list[i];
	for(int i = numElements, j = 0; j < right.numElements; i++, j++)
		newList.list[i] = right.list[j];
	return newList;
}
const ListCollection ListCollection::sublist(int first, int second)
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
const ListCollection ListCollection::sublist(int first)
{
    int size = (numElements - first);
	ListCollection newList(size);
	for(int i = 0; i < size - 1; i++)
		newList.list[i] = 0;
	for(int i = 0; i < size ; i++)
		newList.list[i] = list[(i + first)];
	return newList;
}
const ListCollection ListCollection::sort()
{
    int *newList = new int[numCapacity];
	//numCapacity = numElements;
	for(int i = 0; i < numElements; i++)
		newList[i] = this->getElement(i);
	for(int i = 0; i < numElements-1; i++)
	{
		for(int j = 0; j < numElements - (i - 1); j++)
		{
			if(newList[i] < newList[j])
			{
				int temp = newList[i];
				newList[i] = newList[j];
				newList[j] = temp;
			}
		}
	}
	for(int i = 0; i < numElements; i++)
		list[i] = newList[i];
	return *this;
}
void ListCollection::clear()
{
	delete[] list;
	list = new int[numCapacity];
	numElements = 0;
	/* int runTime = numElements;
    for(int i = 0; i < runTime; i++)
	{
		list[i] = 0;
		numElements--;
	} */
}
int ListCollection::size()
{
    return numElements;
}
int ListCollection::capacity()
{
    return numCapacity;
}
void ListCollection::pushFront(int num)
{
	if(numElements == numCapacity)
		resize(numCapacity * 2);
	numElements++;
	for(int i = numElements - 1; i >= 0; i--)
		list[i + 1] = list[i];
	list[0] = num;
}
void ListCollection::pushBack(int num)
{
	if(numElements == numCapacity)
		resize(numCapacity * 2);
	list[numElements++] = num;
}
int ListCollection::popFront()
{
    int value;
    value = list[0];
	remove(0);
	numElements--;
    return value;
}
int ListCollection::popBack()
{
    //int value;
    //value = list[numElements - 1];
	//remove(numElements - 1);
	numElements--;
    return list[numElements];
}
void ListCollection::insertOrdred(int num)
{
	int temp = numCapacity;
	pushFront(num);
	sort();
	numCapacity = temp;
}
void ListCollection::removeElement(int num)
{
    for(int i = 0; i < numElements; i++)
    {
        if(list[i] == num)
            list[i] = 0;
    }
	numElements--;
}
void ListCollection::insert(int pos, int element)
{
    list[pos] = element;
}
void ListCollection::remove(int num)
{
    if((num < numElements && num >= 0))
	{
		for(int i = num; i < numElements; i++)
			list[i] = list[i + 1];
	}
}