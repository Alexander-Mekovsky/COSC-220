//Name: Alexander Mekovsky
//Date: September 13 2022
//Class: COSC 220
//Assignment: Lab 03 Part 3 Array.h
//Program Objective: To create a class and declare the private and public variables needed to run through the declared array.

#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>

class Array{
    private:
        float *arrayNum;
        float numValues;
    public:
        Array(int);
        ~Array();
        void store(float, int);
        float get(int);
        float highest();
        float lowest();
        float average();
};

#endif