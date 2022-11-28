
//Date: September 19 2022
//Class: COSC 220
//Assignment: Lab 03 Part 2 main.cpp
//Program Objective: This is the main.cpp that brings together the collide.cpp and the collide.h files together. The program starts by declaring an array of 1000 entries and then randomly
//gives them a radius and pair of center coordinates. It then runs a collision function to determine if a pair of circles collide with one another, and if they do, print out a message.

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include "Collide.h"

using namespace std;

int main()
{
    srand(time(0));
    const int SIZE = 1000;
    Collide circles[SIZE];
    for(int i = 0; i < SIZE; i++)
    {
        circles[i].setRadius((rand() % 2) + 1);
        circles[i].setCenter((rand() % 41) - 20, (rand() % 41) - 20);
    }
    for(int i = 0; i < SIZE - 1; i++)
    {
        for(int j = i + 1; j < SIZE; j++)
        {
            if (circles[i].ifCollide(circles[j]) )
            {
                cout << "Circle " << i + 1 << " and circle " << j + 1 << " collide." << endl;
            }
        }
    }

    return 0;
}
