#include <iostream>
#include "IntegerList.h"

using namespace std;

void PopulateList(IntegerList &L, int size)
{
    for (int i = 0; i < size; i++)
        L[i] = i;    
}

void PopulateList2(IntegerList L, int size)
{
    for (int i = 0; i < size; i++)
        L[i] = i;    
}

int main()
{
    IntegerList l1(7);
    IntegerList l2(17);

    for (int i = 0; i < 7; i++)
        l1[i] = i * i;

    cout << "In PopulateList2 with l1" << endl;
    PopulateList2(l1, 7); 
    cout << "Out PopulateList2 with l1" << endl;
    cout << "In PopulateList with l2" << endl;
    PopulateList(l2, 17);
    cout << "Out PopulateList with l2" << endl;

    l1.displayList();
    l2.displayList();

    IntegerList l3 = l1 + l2;

    l3.displayList();

    l3[4] = 100;
    l3.displayList();

    IntegerList l4 = l3.sublist(3, 8);
    l4.displayList();

    IntegerList l5 = l3.sublist(8);
    l5.displayList();

    IntegerList l6 = l3.sublist(3, 800);
    l6.displayList();

    l6.resize(5);
    l4.resize(30);
    l6.displayList();
    l4.displayList();

    IntegerList l7 = l3.sort();
    l3.displayList();
    l7.displayList();

    IntegerList l8 = l7;
    l8.displayList(); 


    return 0;
}
/*
1. PopulateList fills a list with values 0-6, while PopulateList2 fills a list with values 0-16, this is because of the range of the call setting the limit of the
number generation. This results in a larger list of numbers to use.
2. 0 1 2 3 4 5 6 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16.
+ Operator is entered
Entering the constructor IntegerList
+ Operator is exited
3. IntegerList(const IntegerList &obj)
4. IntegerList(int); 
*/
