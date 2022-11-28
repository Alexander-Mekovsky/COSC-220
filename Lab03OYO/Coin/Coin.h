
//Date: September 19 2022
//Class: COSC 220
//Assignment: Lab 03 Part 4 main.cpp
//Program Objective: This is the class declaration for Coin and its private and public functions

#ifndef COIN.H
#define COIN.H

#include <iostream>
#include <string>

using namespace std;

class Coin{
    private:
        string sideUp;
    public:
        Coin();
        void toss();
        string getSideUp();
};

#endif
