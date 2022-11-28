//Name: Alexander Mekovsky
//Date: September 19 2022
//Class: COSC 220
//Assignment: Lab 03 Part 4 main.cpp
//Program Objective: This is where the Coin.cpp and Coin.h come together to make up the main file of the coin flipping program. The program establishes a pointer array of 20 values, which it
//runs through a for loop mimicking a coin flip and changes the side it landed on. It also tallies up the total number of each side. At the end it prints every coin number and the number of
//heads and tails it landed on.

#include <iostream>
#include "Coin.h"
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    srand(time(0));
    const int FLIPS = 20;
    int numHead = 0;
    int numTail = 0;
    Coin *coins;
    coins = new Coin[FLIPS];
    string side = coins->getSideUp();
    cout << "Initial side up: " << side << endl;
    for(int i = 0; i < FLIPS; i++)
    {
        coins[i].toss();
        cout << "Coin number " << i + 1 << " has the side facing up: " << coins[i].getSideUp() << endl;
        string newSide = coins[i].getSideUp();
        if(newSide == "Heads")
            numHead++;
        if(newSide == "Tails")
            numTail++;
    }
    cout << "Number of heads: " << numHead << endl;
    cout << "Number of tails: " << numTail << endl;
    delete[] coins;
    coins = nullptr;
    return 0;
}