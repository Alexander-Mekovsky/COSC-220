#include <iostream>

 #include "PersonData.h"
 #include "CustomerData.h"
 //#include "PreferredCustomer.h"

 using namespace std;

int main() 
 {
 PersonData P1;
 P1.setName("Junyi", "Tu");
 P1.setAddress("1101 Camden Ave.", "Salisbury", "MD", "21801");
 P1.setPhone("410-677-0027");
 P1.PrintRecord();
cout << endl;

 P1.getRecord();
 cout << endl;

 PersonData *P2 = new PersonData();
 P2->setName("John", "Doe");
 P2->setAddress("Nowhere Ave.", "Podunk", "NB", "66666");
 P2->setPhone("123-456-7890");

 P2->PrintRecord();
 cout << endl;
 P2->getRecord();
 cout << endl;

 CustomerData *P3 = new CustomerData();
 P3->setName("Jane", "Doe");
 P3->setAddress("Nowhere Ct.", "Podunk", "NB", "66666");
 P3->setPhone("987-798-1111");
 P3->setNumber(12345);
 P3->setList(false);

 P3->PrintRecord();
 cout << endl;
 P3->getRecord();
 cout << endl;

 delete P2;
 delete P3;
 P2 = nullptr;
 P3 = nullptr;
 
 return 0;
 }