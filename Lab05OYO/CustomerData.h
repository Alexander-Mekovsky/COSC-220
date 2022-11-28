#ifndef CUSTOMERDATA_H_
#define CUSTOMERDATA_H_

#include <iostream>
#include <string>
#include "PersonData.h"

using namespace std;

class CustomerData : public PersonData
{
    protected:
        int customerNumber;
        bool mailingList;
    public:
        CustomerData();
        CustomerData(string, string, string, string, string, string, string, int, bool);
        void setNumber(int);
        void setList(bool);
        int getNumber();
        bool getList();
        virtual void getRecord();
        virtual void PrintRecord();
};

#endif