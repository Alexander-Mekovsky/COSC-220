
//Date: September 13 2022
//Class: COSC 220
//Assignment: Lab 03 Part 2 Collide.h
//Program Objective: To create a class and declare the private and public variables needed to run through the set of circles and collision code.

#ifndef COLLIDE.H
#define COLLIDE.H

#include <iostream>

class Collide
{
    private:
        double radius;
        double pi = 3.141592653589793;
        double x;
        double y;
    public:
        Collide();
        ~Collide();
        Collide(double, double, double);
        void setRadius(double);
        void setCenter(double, double);
        double getCenterX() const;
        double getCenterY() const;
        double getRadius() const;
        double getArea() const;
        double getDiameter() const;
        double getCircumference() const;
        bool ifCollide(Collide) const;

};

#endif
