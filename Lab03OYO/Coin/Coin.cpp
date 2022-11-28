//Name: Alexander Mekovsky
//Date: September 19 2022
//Class: COSC 220
//Assignment: Lab 03 Part 4 Coin.cpp
//Program Objective: This is the Coin.cpp file where the class functions are given directives and code to be used in the main.cpp

#include "Coin.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

using namespace std;

Coin::Coin()
{
    toss();
}
void Coin::toss()
{
    int side = rand() % 2;
    if(side == 0)
    {
        sideUp = "Heads";
    }
    if(side == 1)
    {
        sideUp = "Tails";
    }
}
string Coin::getSideUp()
{
    return sideUp;
}