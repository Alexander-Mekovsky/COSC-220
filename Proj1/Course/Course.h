#ifndef COURSE.H
#define COURSE.H

#include <iostream>
#include <string>

using namespace std;

class Course
{
    protected:
        int code;
        string name;
        float testsScore[3];
        
    public:
        Course();
        Course(int, string, float*);
        void setCode(int);
        int getCode() const;
        void setName(string);
        string getName();
        void setScores(int, float);
        float* getScores();
        friend ostream& operator<<(ostream &, const Course right);
        bool operator==(Course right);
};

#endif