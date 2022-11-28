#include "CustomerData.h"
#include "PersonData.h"
#include <iostream>
#include <string>

using namespace std;

CustomerData::CustomerData() : PersonData()
{
    PersonData();
    customerNumber = 0;
    mailingList = false;
} 
CustomerData::CustomerData(string f, string l, string a, string c, string s, string z, string p, int n, bool j)
{
    firstName = f;
    lastName = l;
    address = a;
    city = c;
    state = s;
    zip = z;
    phone = p;
    customerNumber = n;
    mailingList = j;
}
void CustomerData::setNumber(int n)
{
    customerNumber = n;
}
void CustomerData::setList(bool l)
{
    mailingList = l;
}
int CustomerData::getNumber()
{
    return customerNumber;
}
bool CustomerData::getList()
{
    return mailingList;
}
 void CustomerData::PrintRecord()
{
    string list;
    if(mailingList == 1)
        list = "Yes";
    else if(mailingList == 0)
        list = "No";
    cout << firstName << ", " << lastName << endl;
    cout << address << endl;
    cout << city << ", " << state << " " << zip << endl;
    cout << phone << endl;
    cout << "Customer Number: " << customerNumber << endl;
    cout << "On the Mailing List: " << list << endl;
}
 void CustomerData::getRecord()
{
    string list;
    if(mailingList == 1)
        list = "Yes";
    else if(mailingList == 0)
        list = "No";
    cout << firstName << " " << lastName << " / " << address << " / " << city << ", " << state << " " << zip << " / " << phone << " / C#: " << customerNumber << " / ML: " << list;
}
