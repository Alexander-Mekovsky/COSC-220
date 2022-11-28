#ifndef PREFERREDCUSTOMER_H_
#define PREFERREDCUSTOMER_H_

#include <iostream>
#include <string>
#include "CustomerData.h"

using namespace std;

class PreferredCustomer : public CustomerData
{
    protected:
        double purchasesAmount;
        double discountLevel;
    public:
         PreferredCustomer();
         PreferredCustomer(string, string, string, string, string, string, string, int, bool, double);
         virtual void getRecord();
         virtual void PrintRecord();
         void setAmount(double);
         void setDiscount();
         double getDiscount();
         double getAmount();
};

#endif