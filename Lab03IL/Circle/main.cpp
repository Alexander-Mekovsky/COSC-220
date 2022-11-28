//Name: Alexander Mekovsky
//Date: September 13 2022
//Class: COSC 220
//Assignment: Lab 03 Part 1 main.cpp
//Program Objective: This is where the Circle.cpp and the Circle.h files meet up to display the computations in the main file.

#include <iostream>
#include "Circle.h"

using namespace std;

int main()
{
    Circle cir;
    double circRadius;
    
    cout << "Please enter the radius of the circle: ";
    cin >> circRadius;

    cir.setRadius(circRadius);

    cout << "Here are all the computations: " << endl;
    cout << "Area: " << cir.getArea() << endl;
    cout << "Diameter: " << cir.getDiameter() << endl;
    cout << "Circumference: " << cir.getCircumference() << endl;
    return 0;
}