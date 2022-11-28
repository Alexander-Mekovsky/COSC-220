//Name: Alexander Mekovsky
//Date: September 9, 2022
//Class: COSC 220
//Assignment: Lab 02 Part 3
//Program Objective: To randomly generate an array with a user defined size. The program then duplicates the randomly generated array into a new array, and the duplicated array is the one
//that is to be sorted into ascending order. The program then prints out the randomly generated array. After this, the program uses a bubble sort algorithm to sort the algorithm from least 
//to greatest. It then prints out the newly sorted algorithm and checks to see if it's sorted or not. If it is, it prints a message saying so, if not, then it prints a message saying
//that the array is not sorted.

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int *duplicateArray(const int *, int);
void displayArray(const int *, int);
int *getRandomNumbers(int);
void sort(int *, int);
bool sorted(const int *, int);

int main()
{
    int size;
    cout << "Input Array Size: ";
    cin >> size;
    if(size <= 0)
    {
        do
        {
            cout << "Invalid array size, please enter another value: ";
            cin >> size;
        } while (size <= 0);
    }

    int *arrayOld = getRandomNumbers(size);
    int *arrayNew = duplicateArray(arrayOld, size);
    displayArray(arrayOld, size);
    sort(arrayNew, size);
    if (sorted(arrayNew, size))
        cout << "Array is sorted." << endl;
    else
        cout << "Array is not sorted." << endl;

    delete[] arrayOld;
    arrayOld = nullptr;
    delete[] arrayNew;
    arrayNew = nullptr;
    return 0;
}

int *duplicateArray(const int *arr, int size)
{
    int *newArr = nullptr;
    newArr = new int [size];
    for(int i = 0; i < size; i++)
    {
        *(newArr + i) = *(arr + i);
    }
    return newArr;
}

void displayArray(const int *arr, int size)
{
    for(int i = 0; i < size; i++)
    {
        cout << *(arr + i) << " ";
    }
    cout << endl;
}

int *getRandomNumbers(int size)
{
    int *arr = nullptr;
    arr = new int[size];
    srand(time(0));
    for(int i = 0; i < size; i++)
    {
        *(arr + i) = rand();
        cout << *(arr + i) << endl;
    }
    return arr;
}

void sort(int *arr, int size)
{
    int limit, index;
    for(limit = size - 1; limit > 0; limit--)
    {
        for(index = 0; index < limit; index++)
        {
            if(*(arr + index) > *(arr + (index + 1)))
            {
                int temp = *(arr + index);
                *(arr + index) = *(arr + (index + 1));
               *(arr + (index + 1)) = temp;
            }
        }
    }
    for(int i = 0; i < size; i++)
    {
        cout << *(arr + i) << " ";
    }
    cout << endl;
}

bool sorted(const int *arr, int size)
{
    for(int i = 0; i < size - 1; i++)
    {
        if(*(arr + (i + 1)) < *(arr + i))
        {
            return false;
        }
    }
    return true;
}