#include <iostream>
#include <cstdlib>
#include "NumDays.h"

using namespace std;

NumDays::NumDays(double hours, double days)
{
    numHours = hours;
    numDays = days;
}
const NumDays NumDays::operator+(const NumDays &right)
{
    NumDays temp;
    temp.numHours = numHours + right.numHours;
    return temp;
}
const NumDays NumDays::operator-(const NumDays &right)
{
    NumDays temp;
    temp.numHours = numHours - right.numHours;
    return temp;
}
void NumDays::operator++()
{
    numHours++;
    this->dayConversion();
}
void NumDays::operator--()
{
    numHours--;
    this->dayConversion();
}
void NumDays::operator++(int)
{
    ++numHours;
    this->dayConversion();
}
void NumDays::operator--(int)
{
    --numHours;
    this->dayConversion();
}
void NumDays::dayConversion()
{
    numDays = numDays + (numHours / 8);
    numHours = 0;
}
void NumDays::setHours(double h)
{
    numHours = h;
}
double NumDays::getHours()
{
    return numHours;
}
void NumDays::setDays(double d)
{
    numDays = d;
}
double NumDays::getDays()
{
    return numDays;
}
void NumDays::setMonths(double m)
{
    numMonths = m;
}
double NumDays::getMonths()
{
    return numMonths;
}