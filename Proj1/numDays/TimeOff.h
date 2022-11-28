#ifndef TIMEOFF_H_
#define TIMEOFF_H_
#include "NumDays.h"

#include <iostream>
#include <string>

using namespace std;

class TimeOff
{
    protected:
        string name;
        int id;
        NumDays maxSickDays;
        NumDays sickTaken;
        NumDays maxVacation;
        NumDays vacTaken;
        NumDays maxUnpaid;
        NumDays unpaidTaken;
    public:
        TimeOff(string, int);
        ~TimeOff();

        void setMaxSickDays(NumDays a) {maxSickDays = a;}
        void setSickTaken(NumDays a) {sickTaken = a;}
        void setMaxVacation(NumDays a) {maxVacation = a;} 
        void setVacTaken(NumDays a) {vacTaken = a;}
        void setMaxUnpaid(NumDays a) {maxUnpaid = a;}
        void setUnpaidTaken(NumDays a) {unpaidTaken = a;}
        void setName(string a) {name = a;}
        void setID(int a) {id = a;}

        NumDays getMaxSickDays() {return maxSickDays;}
        NumDays getSickTaken() {return sickTaken;}
        NumDays getMaxVacation() {return maxVacation;}
        NumDays getVacTaken() {return vacTaken;}
        NumDays getMaxUnpaid() {return maxUnpaid;}
        NumDays getUnpaidTaken() {return unpaidTaken;}
        string getName() {return name;}
        int getID() {return id;}

        void addTime(int months);
};

#endif