//Name: Alexander Mekovsky
//Date: September 9, 2022
//Class: COSC 220
//Assignment: Lab 02 Part 4
//Program Objective: The program takes two establishes arrays and puts them through five different functions. The first function combines both arrays into one large array, the second function
//takes the combined array and reverses it, the third function expands the array and fills in any gaps with zeroes, the fourth function shifts the last entry in the array and shifts it to the
//very beginning of the array, and the fifth function shifts the first entry in the array into the very end of the array. All of these functions are printed out in order after the initial
//arrays were printed.

#include <iostream>

using namespace std;

void displayArray(const int *arr, int size)
{
    for(int i = 0; i < size; i++)
    {
        cout << *(arr + i) << " ";
    }
    cout << endl;
}

int* concatenateArray(int*, int*, int, int);
int* reverseArray(int*, int);
int* expandArray(int*, int);
int* rightShiftArray(int*, int);
int* leftShiftArray(int*, int);


int main()
{
    int arrayOne[] = {1, 2, 3, 4, 5};
    int arrayTwo[] = {1, 3, 5, 7, 9, 11, 13};
    int sizeOne = 5;
    int sizeTwo = 7;
    displayArray(arrayOne, sizeOne);
    displayArray(arrayTwo, sizeTwo);

    int *combinedArray = concatenateArray(arrayOne, arrayTwo, sizeOne, sizeTwo);
    displayArray(combinedArray, sizeOne + sizeTwo);

    int *reversedArray = reverseArray(combinedArray, sizeOne + sizeTwo);
    displayArray(reversedArray, sizeOne + sizeTwo);

    int *expandedArray = expandArray(arrayOne, sizeOne);
    displayArray(expandedArray, sizeOne * 2);

    int *rightArray = rightShiftArray(arrayTwo, sizeTwo);
    displayArray(rightArray, sizeTwo);

    int *leftArray = leftShiftArray(arrayTwo, sizeTwo);
    displayArray(leftArray, sizeTwo);
    
    delete[] combinedArray;
    combinedArray = nullptr;

    delete[] reversedArray;
    reversedArray = nullptr;

    delete[] expandedArray;
    expandedArray = nullptr;

    delete[] rightArray;
    rightArray = nullptr;

    delete[] leftArray;
    leftArray = nullptr;

    return 0;
}

int* concatenateArray(int* arr1, int* arr2, int size1, int size2)
{
    int *arrayCom = nullptr;
    int newSize = size1 + size2;
    arrayCom = new int[newSize];
    for(int i = 0; i < size1; i++)
    {
        *(arrayCom + i) = *(arr1 + i);
    }
    for(int i = 0; i < size2; i++)
    {
        *(arrayCom + (i + size1)) = *(arr2 + i);
    }
    return arrayCom;
}

int* reverseArray(int* arr1, int size1)
{
    int *arrayRev = nullptr;
    arrayRev = new int[size1];
    for(int i = 0, j = size1 - 1; i < size1; i++, j--)
    {
        *(arrayRev + i) = *(arr1 + j);
    }
    return arrayRev;
}

int* expandArray(int* arr1, int size1)
{
    int *arrayExp = nullptr;
    arrayExp = new int[size1 * 2];
    for(int i = 0; i < size1; i++)
    {
        *(arrayExp + i) = *(arr1 + i);
    }
    for(int i = size1; i < size1 * 2; i++)
    {
        *(arrayExp + i) = 0;
    }
    return arrayExp;
}

int* rightShiftArray(int* arr1, int size1)
{
    int *arrayRight = nullptr;
    arrayRight = new int[size1];
    *(arrayRight) = *(arr1 + size1 - 1);
    for(int i = 1; i < size1; i++)
    {
        *(arrayRight + i) = *(arr1 + (i - 1));
    }
    return arrayRight;
}

int* leftShiftArray(int* arr1, int size1)
{
    int *arrayLeft = nullptr;
    arrayLeft = new int[size1];
    *(arrayLeft + size1 - 1) = *(arr1);
    for(int i = 1; i < size1; i++)
    {
        *(arrayLeft + (i - 1)) = *(arr1 + i);
    }
    return arrayLeft;
}
