#include "Student.h"
#include "Course.h"
#include <iostream>

using namespace std;

Student::Student()
{

}
Student::Student(int i, string n)
{
    id = i;
    name = i;
}
Student::~Student()
{

}
Student::Student(const Student &right)
{
    id = right.id;
    name = right.name;
    for(int i = 0; i < numCourses; i++)
    {
        array[i] = right.array[i];
    }
}
const Student Student::operator=(const Student &right)
{
    delete[] array;
    id = right.id;
    name = right.name;
    for(int i = 0; i < 3; i++)
    {
        array[i] = right.array[i];
    }
    return *this;
}
void Student::setID(int i)
{
    id = i;
}
int Student::getID()
{
    return id;
}
void Student::setName(string n)
{
    name = n;
}
string Student::getName()
{
    return name;
}

Course Student::getArray(int numCourses) const
{
    return *(array + numCourses);
}
ostream& operator<<(ostream&strm, const Student &right)
{
    strm<<"Name: " << right.name << " ID: " << right.id << endl;
    for(int i = 0; i < right.numCourses; i++)
    {
        strm << *(right.array + i) << endl;
    }
    return strm;
}
void Student::addCourse(Course c)
{
    Course *newArr = new Course[numCourses];
    for(int i = 0; i < numCourses; i++)
    {
        *(newArr + i) = *(array + i);
    }
    numCourses++;
    array = new Course[numCourses];
    for(int i = 0; i < numCourses - 1; i++)
    {
        *(array + i) = *(newArr + i);
    }
    *(array + numCourses - 1) = c;
}
void Student::deleteCourse(Course c)
{
    int count = 0;
    for(int i = 0; i < numCourses; i++)
    {
        if(*(array + i) == c)
            count++;
    }
    Course *newArr = new Course[numCourses];
    int newCount = 0;
    for(int i =0; i < numCourses; i++)
    {
        if(!(*(array +  i) == c))
            {
                *(newArr + i) = *(array + i);
                newCount++;
            }
    }
    delete[] array;
    numCourses = count;
    array = new Course[numCourses];
    for(int i = 0; i < numCourses; i++)
    {
        *(array + i) = *(newArr + i);
    }
}