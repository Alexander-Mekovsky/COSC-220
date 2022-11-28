//Name: Alexander Mekovsky
//Date: September 13 2022
//Class: COSC 220
//Assignment: Lab 03 Part 1 Circle.cpp
//Program Objective: To declare each established variable with how they interact with the rest of the program, this includes constructors and destructors

#include "Circle.h"

using namespace std;

Circle::Circle()
{
    radius = 0.0;
}
Circle::Circle(double r)
{
    radius = r;
}
void Circle::setRadius(double r)
{
    if(r>=0)
    {
        radius = r;
    }
    else
    {
        radius = 0;
    }
}
double Circle::getRadius() const
{
    return radius;
}
double Circle::getArea() const
{
    return (pi * (radius * radius));
}
double Circle::getDiameter() const
{
    return (radius + radius);
}
double Circle::getCircumference() const 
{
    return (2 * pi * radius);
}
Circle::~Circle()
{

}