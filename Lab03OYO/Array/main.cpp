
//Date: September 19 2022
//Class: COSC 220
//Assignment: Lab 03 Part 3 main.cpp
//Program Objective: This is the main.cpp file where Array.h and Array.cpp are brought together. The program starts by the user declaring their own array by choosing the size and values to be
//placed in the array. The program then prints out the entire array and runs code to determine the largest and lowest values along with the average of the array and prints them out.

#include <iostream>
#include "Array.h"

using namespace std;

int main()
{
    int SIZE = 0;
    float entry = 0;
    cout << "Please enter the array size: ";
    cin >> SIZE;
    Array newArray(SIZE);

    for(int i = 0; i < SIZE; i++)
    {
        cout << "Please enter the valve for array value " << i + 1 << ": ";
        cin >> entry;
        newArray.store(entry, (int) i);
    }
    float high = newArray.highest();
    float low = newArray.lowest();
    float ave = newArray.average();
    for(int i = 0; i < SIZE; i++)
    {
        cout << "Array value " << i + 1 << ": " << newArray.get(i) << endl;
    }
    cout << "Largest value of the array is " << high << endl;
    cout << "Lowest value of the array is " << low << endl;
    cout << "Average value of the array is " << ave << endl;
    return 0;
}
