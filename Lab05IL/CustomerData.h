#ifndef CUSTOMERDATA.H
#define CUSTOMERDATA.H

#include <iostream>
#include <string>
#include "PersonData.h"

using namespace std;

class CustomerData : public PersonData
{
    private:
        int customerNumber;
        bool mailingList;
    public:
        CustomerData();
        void setNumber(int);
        void setList(bool);
        int getNumber();
        bool getList();
        void getRecord();
        void PrintRecord();
};

#endif