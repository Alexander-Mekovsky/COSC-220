#include <iostream>
#include <cstdlib>
#include <string>
#include "NumDays.h"
#include "TimeOff.h"

using namespace std;

TimeOff::TimeOff(string n, int i)
{
    name = n;
    id = i;
}
TimeOff::~TimeOff()
{

}
void TimeOff::addTime(int months) {
     double total = maxVacation.getHours() + (8 * maxVacation.getDays());

     if(total + (12 * months) >= 240)
         maxVacation.setDays(30);
     else {
          NumDays temp1(12 * months,0);
          maxVacation = maxVacation + temp1;
          maxVacation.dayConversion();
      }

     NumDays temp2(8 * months,0);
     maxSickDays = maxSickDays + temp2;
     maxSickDays.dayConversion();

     NumDays temp3(12 * months,0);
     maxUnpaid = maxUnpaid + temp3;
     maxUnpaid.dayConversion();
}