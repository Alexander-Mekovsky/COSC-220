#ifndef PERSONDATA.H
#define PERSONDATA.H

#include <iostream>
#include <string>

using namespace std;

class PersonData
{
    protected:
        string lastName;
        string firstName;
        string address;
        string city;
        string state;
        string zip;
        string phone;
    public:
        PersonData();
        void setName(string, string);
        void setAddress(string, string, string, string);
        void setPhone(string);
        string getLastName();
        string getFirstName();
        string getAddress();
        string getCity();
        string getState();
        string getZip();
        string getPhone();
        void getRecord();
        void PrintRecord();
};

#endif