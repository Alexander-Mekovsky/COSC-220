//Name: Alexander Mekovsky
//Date: September 13 2022
//Class: COSC 220
//Assignment: Lab 03 Part 2 Collide.cpp
//Program Objective: To declare each established variable with how they interact with the rest of the program, this includes constructors and destructors

#include <cmath>
#include "Collide.h"

using namespace std;

Collide::Collide()
{
    radius = 0.0;
    x = 0.0;
    y = 0.0;
}
Collide::Collide(double r, double x, double y)
{
    radius = r;
    this->x = x;
    this->y = y;
}
void Collide::setRadius(double r)
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
void Collide::setCenter(double x, double y)
{
    x = x;
    y = y;
}
double Collide::getCenterX() const
{
    return x;
}
double Collide::getCenterY() const
{
    return y;
}
double Collide::getRadius() const
{
    return radius;
}
double Collide::getArea() const
{
    return (pi * (radius * radius));
}
double Collide::getDiameter() const
{
    return (radius + radius);
}
double Collide::getCircumference() const 
{
    return (2 * pi * radius);
}
bool Collide::ifCollide(Collide circ) const
{
    double distance = sqrt(pow(circ.getCenterX() - this->x, 2) + pow(circ.getCenterY() - this->y, 2) * 1.0);
    double sum = circ.getRadius() + this->radius;
    return distance <= sum;

}
Collide::~Collide()
{
    
}