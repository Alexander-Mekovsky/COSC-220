#ifndef STUDENT.H
#define STUDENT.H

#include "Course.h"
#include <iostream>
#include <string>

using namespace std;

class Student
{
    protected:
        int id;
        string name;
        Course *array;
        int numCourses = 0; 
    public:
        Student();
        Student(int, string);
        Student(const Student &right);
        ~Student();
        const Student operator=(const Student &right);
        friend ostream& operator<<(ostream& strm, const Student &right);
        void setID(int);
        int getID();
        void setName(string);
        string getName();
        Course getArray(int) const;
        void addCourse(Course);
        void deleteCourse(Course);
};

#endif