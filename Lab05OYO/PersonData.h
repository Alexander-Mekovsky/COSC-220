#ifndef PERSONDATA_H_
#define PERSONDATA_H_

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
        PersonData(string, string, string, string, string, string, string);
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
        // virtual void setup();
        virtual void getRecord();
        virtual void PrintRecord();
};

#endif