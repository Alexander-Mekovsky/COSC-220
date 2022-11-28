#ifndef NUMDAYS_H_
#define NUMDAYS_H_

#include <iostream>

using namespace std;

class NumDays
{
    protected:
       double numHours;
       double numDays;
       double numMonths;
    public:
        void setHours(double);
        void setDays(double);
        void setMonths(double);
        double getMonths();
        double getHours();
        double getDays();
        NumDays(double hours = 0, double days = 0);
        const NumDays operator+(const NumDays &);
        const NumDays operator-(const NumDays &);
        void operator++();
        void operator--();
        void operator++(int);
        void operator--(int);
        void dayConversion();
};

#endif