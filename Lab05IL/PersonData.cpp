#include "PersonData.h"
#include <iostream>
#include <string>

using namespace std;

PersonData::PersonData()
{
    firstName = "";
    lastName = "";
    address = "";
    city = "";
    state = "";
    zip = "";
    phone = "";
}
void PersonData::setName(string f, string l)
{
    firstName = f;
    lastName = l;
}
void PersonData::setAddress(string a, string c, string s, string z)
{
    address = a;
    city = c;
    state = s;
    zip = z;
}
void PersonData::setPhone(string p)
{
    phone = p;
}
string PersonData:: getFirstName()
{
    return firstName;
}
string PersonData:: getLastName()
{
    return lastName;
}
string PersonData:: getAddress()
{
    return address;
}
string PersonData:: getCity()
{
    return city;
}
string PersonData:: getState()
{
    return state;
}
string PersonData:: getZip()
{
    return zip;
}
string PersonData:: getPhone()
{
    return phone;
}
void PersonData::PrintRecord()
{
    cout << firstName << ", " << lastName << endl;
    cout << address << endl;
    cout << city << ", " << state << " " << zip << endl;
    cout << phone << endl;
}
void PersonData::getRecord()
{
    cout << firstName << " " << lastName << " / " << address << " / " << city << ", " << state << " " << zip << " / " << phone;
}