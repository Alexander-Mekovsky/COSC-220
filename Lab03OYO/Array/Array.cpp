
//Date: September 19 2022
//Class: COSC 220
//Assignment: Lab 03 Part 3 Array.cpp
//Program Objective: This is the Array.cpp files where directives and code is given to the class declarations of Array.h

#include "Array.h"

using namespace std;

Array::Array(int size)
{
    arrayNum = new float[size];
    numValues = size;
    for(int i = 0; i < size; i++)
    {
        arrayNum[size] = 0;
    }
}
Array::~Array()
{
    delete[] arrayNum;
}
void Array::store(float value, int num)
{
    arrayNum[num] = value;
}
float Array::get(int num)
{
    return arrayNum[num];
}
float Array::highest()
{
    float high = *(arrayNum + 0);
    for(int i = 0; i < numValues; i++)
    {
        if(*(arrayNum + i) > high)
        {
            high = *(arrayNum + i);
        }
    }
    return high;
}
float Array::lowest()
{
    float low = *(arrayNum + 0);
    for(int i = 1; i < numValues; i++)
    {
        if(*(arrayNum + i) < low)
        {
            low = *(arrayNum + i);
        }
    }
    return low;
}
float Array::average()
{
    float ave = 0;
    float ticks = 0;
    for(int i = 0; i < numValues; i++)
    {
        ave+= *(arrayNum + i);
        ticks++;
    }
    return (ave / ticks);
}
