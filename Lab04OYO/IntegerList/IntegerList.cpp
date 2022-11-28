#include <iostream>
#include <cstdlib>
#include "IntegerList.h"

using namespace std;

IntegerList::IntegerList(int size) {
	cout << "Entering the constructor IntegerList" << endl;
	list = new int[size];
	numElements = size;
	for (int ndx = 0; ndx < size; ndx++)
		list[ndx] = 0;
}

IntegerList::~IntegerList() {
	cout << "Entering the destructor IntegerList" << endl;
	delete[] list;
}

IntegerList::IntegerList(const IntegerList &obj) {
	cout << "Entering the copy constructor" << endl;
	numElements = obj.numElements;
	list = new int[numElements];
	for (int i = 0; i < numElements; i++)
		list[i] = obj.list[i];
}

const IntegerList IntegerList::operator=(const IntegerList &right) {
	cout << "Entering the assignment statement" << endl;
	delete[] list;
	numElements = right.numElements;
	list = new int[numElements];
	for (int i = 0; i < numElements; i++)
		list[i] = right.list[i];

	return *this;
}

const IntegerList IntegerList::operator+(const IntegerList &right){
	cout << "+ Operator is entered" << endl;
	IntegerList newList(numElements + right.numElements);
	for(int i = 0; i < numElements; i++)
	{
		newList.list[i] = list[i];
	}
	for(int i = numElements, j = 0; j < right.numElements; i++, j++)
	{
		newList.list[i] = right.list[j];
	}
	cout << "+ Operator is exited" << endl;
	return newList;
}

bool IntegerList::isValid(int element) const {
	bool status;

	if (element < 0 || element >= numElements)
		status = false;
	else
		status = true;
	return status;
}

void IntegerList::setElement(int element, int value) {
	if (isValid(element))
		list[element] = value;
	else {
		cout << "Error: Invalid subscript\n";
		exit(EXIT_FAILURE);
	}
}

int IntegerList::getElement(int element) const {
	if (isValid(element))
		return list[element];
	else {
		cout << "Error: Invalid subscript: Returning 0. \n";
		return 0;
	}
}
void IntegerList::displayList() const
{
    for (int i = 0; i < numElements; i++)
        cout << list[i] << " ";
    cout << endl;
}
int& IntegerList::operator[](const int &sub) {
	//cout << "The [] operator is being called with value: " << sub << endl;
	if(sub < 0)
		return list[0];
	if(sub > numElements - 1)
		return list[numElements - 1];
	if (isValid(sub))
		return list[sub];
	else {
		cout << "Error: Invalid subscript\n";
		exit(EXIT_FAILURE);
	}
}

void IntegerList::resize(int newSize){
	cout << "Called resize" << endl;
	int *newList = new int[newSize];
	for(int i = 0; i < newSize; i++)
	{
		if(i >= numElements)
			*(newList + i) = 0;
		else if (i < numElements)
			*(newList + i) = *(list + i);
	}
	numElements = newSize;
	/* for(int i = 0; i < newSize; i++)
	{
		*(list + i) = *(newList + i);
	} */
	delete[] list;
	list = newList;

}

const IntegerList IntegerList::sublist(int first, int second)
{
	cout << "In sublist with two ranges" << endl;
	if(second > numElements - 1)
		second = numElements - 1;
	int newSize = second - first + 1;
	IntegerList newList(newSize);
	for(int i = 0; i < (second - first + 1); i++)
	{
		newList.list[i] = list[(i + first)];
	}
	return newList;
}

const IntegerList IntegerList::sublist(int first)
{
	cout << "called sublist with one range" << endl;
	int m = (numElements - first);
	IntegerList newList(m);
	for(int i = 0; i < m - 1; i++)
	{
		newList.list[i] = 0;
	}
	for(int i = 0; i < m ; i++)
	{
		newList.list[i] = list[(i + first)];
	}
	return newList;
}
const IntegerList IntegerList::sort()
{
	cout << "In sort" << endl;
	IntegerList newList(numElements);
	for(int i = 0; i < numElements; i++)
	{
		newList.list[i] = list[i];
	}
	for(int i = 0; i < numElements; i++)
	{
		for(int j = 0; j < numElements; j++)
		{
			if(newList[i]<newList[j])
			{
				int temp = newList[i];
				newList[i] = newList[j];
				newList[j] = temp;
			}
		}
	}
	return newList;
}


