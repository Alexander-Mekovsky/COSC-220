//Name: Alexander Mekovsky
//Date: September 13 2022
//Class: COSC 220
//Assignment: Lab 03 Part 1 Circle.h
//Program Objective: To create a class and declare the private and public variables needed to make computations of a circle.

#ifndef CIRCLE.H
#define CIRCLE.H

#include <iostream>

class Circle{
    private:
        double radius;
        double pi = 3.141592653589793;
    public:
        Circle();
        ~Circle();
        Circle(double);
        void setRadius(double);
        double getRadius() const;
        double getArea() const;
        double getDiameter() const;
        double getCircumference() const;
};

#endif