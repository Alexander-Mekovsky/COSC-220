#include "CustomerData.h"
#include "PersonData.h"
#include <iostream>
#include <string>

using namespace std;

CustomerData::CustomerData()
{
    customerNumber = 0;
    mailingList = false;
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
