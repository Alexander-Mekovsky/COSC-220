#include <iostream>
#include <string>

#include "PersonData.h"
#include "CustomerData.h"
#include "PreferredCustomer.h"

using namespace std;

int main() 
{
    PersonData *arr[10];
    string last, first, address, city, state, zip, phone;
    int choice, databaseSize = 0, number, amount;
    char list;
    bool mail;
    do
    {
        cout << "1. Add Personal Data Object" << endl;
        cout << "2. Add Customer Data Object" << endl;
        cout << "3. Add Preferred Customer Data Object" << endl;
        cout << "4. View Database Long Form" << endl;
        cout << "5. View Database Short Form" << endl;
        cout << "6. Quit" << endl;
        cout << "Choice: ";
        cin >> choice;
        if(choice == 1)
        {
            //arr[databaseSize] = new PersonData();
            cout << "Input Last Name: ";
            cin >> last;
            cout << "Input First Name: ";
            cin >> first;
            //arr[databaseSize]->setName(last, first);
            cout << "Input Street Address: ";
            cin >> address;
            cout << "Input City: ";
            cin >> city;
            cout << "Input State: ";
            cin >> state;
            cout << "Input Zip Code: ";
            cin >> zip;
            //arr[databaseSize]->setAddress(address, city, state, zip);
            cout << "Input Phone Number: ";
            cin >> phone;
            //arr[databaseSize]->setPhone(phone);
            arr[databaseSize] = new PersonData(last, first, address, city, state, zip, phone);
            databaseSize++;
        }
        if(choice == 2)
        {
           // arr[databaseSize] = new CustomerData();
            cout << "Input Last Name: ";
            cin >> last;
            cout << "Input First Name: ";
            cin >> first;
            //arr[databaseSize]->setName(last, first);
            cout << "Input Street Address: ";
            cin >> address;
            cout << "Input City: ";
            cin >> city;
            cout << "Input State: ";
            cin >> state;
            cout << "Input Zip Code: ";
            cin >> zip;
            //arr[databaseSize]->setAddress(address, city, state, zip);
            cout << "Input Phone Number: ";
            cin >> phone;
            //arr[databaseSize]->setPhone(phone);
            cout << "Input Customer Number: ";
            cin >> number;
            //arr[databaseSize]->setNumber(number);
            cout << "Do they wish to be on the mailing list? (Y/N): ";
            cin >> list;
            list = (tolower(list));
            if(list == 'n')
                mail = false;
            if(list == 'y')
                mail = true;
            //arr[databaseSize]->setList(mail);
            arr[databaseSize] = new CustomerData(last, first, address, city, state, zip, phone, number, mail);
            databaseSize++;
        }
        if(choice == 3)
        {   
            // arr[databaseSize] = new CustomerData();
            cout << "Input Last Name: ";
            cin >> last;
            cout << "Input First Name: ";
            cin >> first;
            //arr[databaseSize]->setName(last, first);
            cout << "Input Street Address: ";
            cin >> address;
            cout << "Input City: ";
            cin >> city;
            cout << "Input State: ";
            cin >> state;
            cout << "Input Zip Code: ";
            cin >> zip;
            //arr[databaseSize]->setAddress(address, city, state, zip);
            cout << "Input Phone Number: ";
            cin >> phone;
            //arr[databaseSize]->setPhone(phone);
            cout << "Input Customer Number: ";
            cin >> number;
            //arr[databaseSize]->setNumber(number);
            cout << "Do they wish to be on the mailing list? (Y/N): ";
            cin >> list;
            list = (tolower(list));
            if(list == 'n')
                mail = false;
            if(list == 'y')
                mail = true;
            //arr[databaseSize]->setList(mail);
            cout << "Input Purchases Amount: ";
            cin >> amount;
            //arr[databaseSize]->setAmount(amount);
            arr[databaseSize] = new PreferredCustomer(last, first, address, city, state, zip, phone, number, mail, amount);
            databaseSize++;
        }
        if(choice == 4)
        {
            for(int i = 0; i < databaseSize; i++)
            {
                arr[i]->PrintRecord();
                cout << endl;
            }
        }
        if(choice == 5)
        {
            for(int i = 0; i < databaseSize; i++)
            {
                arr[i]->getRecord(); 
                cout << endl;
            }
        }
    } while (choice != 6 && databaseSize < 10);
    cout << "Ended program." << endl;
    return 0;
}