//Alex Mekovsky October 7, 2022

#include "Course.h"
#include "Student.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
    Student stud;
    Course newClass;
    string n, tempName;
    int i, numClass, tempCode;
    cout << "Student Name: ";
    cin >> n;
    stud.setName(n);
    cout << "Student ID: ";
    cin >> i;
    stud.setID(i);
    cout << "How many classes does " << stud.getName() << " have? ";
    cin >> numClass;
    for(int i = 0; i < numClass; i++)
    {
        cout << "What is the code for class number " << i + 1 << ": ";
        cin >> tempCode;
        newClass.setCode(tempCode);
        cout << "What is the name for class number " << i + 1 << ": ";//
        cin >> tempName;
        newClass.setName(tempName);
        for(int j = 0; j < 3; j++)
        {
            float grade;
            cout << "What is the grade for test number " << j + 1 << ": ";
            cin >> grade;
            newClass.setScores(j, grade);
            stud.addCourse(newClass); 
        }
    }
        int numDelete;
        cout << "Enter the number of courses you want to be deleted: ";
        cin >> numDelete;
        for(int i = 0; i < numDelete; i++)
        {
            cout << "What is the code for the class you want to delete: ";
            cin >> tempCode;
            newClass.setCode(tempCode);
            cout << "What is the name for the class you want to delete: ";
            cin >> tempName;
            newClass.setName(tempName);
            stud.deleteCourse(newClass);
        }
    cout << stud << endl;
    for(int i = 0; i < numClass; i++)
        cout << newClass << endl;
    return 0;
}