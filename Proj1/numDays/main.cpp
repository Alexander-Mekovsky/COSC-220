//Alex Mekovsky October 7, 2022

#include "NumDays.h"
#include "TimeOff.h"
#include <iostream>

using namespace std;

int main()
{
    //A sick day per month? Get a better job
    TimeOff emp("d", 1);
    int numMonths, i;
    string n;
    cout << "Employee name: ";
    cin >> n;
    emp.setName(n);
    cout << "Employee ID number: ";
    cin >> i;
    emp.setID(i);
    cout << "How many months has " << emp.getName() << " worked for the company? ";
    cin >> numMonths;
    emp.addTime(numMonths);
    cout << "Employee Name: " << emp.getName() << "       Employee ID: " << emp.getID() << endl;
    cout << emp.getName() << "'s max vacation days: " << emp.getMaxVacation().getDays() << endl;
    cout << emp.getName() << "'s max sick days: " << emp.getMaxSickDays().getDays() << endl;
    cout << emp.getName() << "'s max unpaid days: " << emp.getMaxUnpaid().getDays() << endl;
    return 0;
}