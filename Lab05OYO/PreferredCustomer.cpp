#include "PreferredCustomer.h"
#include "CustomerData.h"
#include <iostream>
#include <string>

using namespace std;

PreferredCustomer::PreferredCustomer() : CustomerData()
{
    CustomerData();
    purchasesAmount = 0;
    discountLevel = 0;
}
PreferredCustomer::PreferredCustomer(string f, string l, string a, string c, string s, string z, string p, int n, bool j, double pur)
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
    purchasesAmount = pur;
    setDiscount();
}
void PreferredCustomer::setAmount(double a)
{
    purchasesAmount = a;
}
void PreferredCustomer::setDiscount()
{
    if(purchasesAmount >= 500)
        discountLevel = 5;
    else if(purchasesAmount >= 1000)
        discountLevel = 6;
    else if(purchasesAmount >= 1500)
        discountLevel = 7;
    else if(purchasesAmount >= 2000)
        discountLevel = 10;
    else
        discountLevel = 0;       
}
double PreferredCustomer::getDiscount()
{
    return discountLevel;
}
double PreferredCustomer::getAmount()
{
    return purchasesAmount;
}
void PreferredCustomer::getRecord()
{
    CustomerData::getRecord();
    cout << " / Account: " << purchasesAmount << " / Discount: " << discountLevel << "%" << endl;
}
void PreferredCustomer::PrintRecord()
{
    CustomerData::PrintRecord();
    cout << "Purchases Amount: " << purchasesAmount << endl;
    cout << "Discount Level: " << discountLevel << "%" << endl;
}