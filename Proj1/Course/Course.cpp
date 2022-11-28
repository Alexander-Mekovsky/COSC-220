#include "Course.h"
#include <iostream>

using namespace std;

Course::Course()
{
    code = 120;
    name = "CSI";
    testsScore[0] = 0.0;
    testsScore[1] = 0.0;
    testsScore[2] = 0.0;
}
Course::Course(int c, string n, float* s)
{
    code = c;
    name = n;
    testsScore[0] = s[0];
    testsScore[1] = s[1];
    testsScore[2] = s[2];
}
void Course::setCode(int c)
{
    code = c;
}
int Course::getCode() const
{
    return code;
}
void Course::setName(string n)
{
    name = n;
}
string Course::getName()
{
    return name;
}
void Course::setScores(int i,float s)
{
    testsScore[i] = s;
}
float* Course::getScores()
{
    return testsScore;
}
ostream &operator<<(ostream &newStrm, const Course right)
{
    newStrm << "Code: " << right.code << " Name: " << right.name << " Score 1: " << right.testsScore[0] << " Score 2: " << right.testsScore[1] << " Score 3: " << right.testsScore[2] << endl;
}
bool Course::operator==(Course right)
{
    if(code == right.code)
    {
        if(name == right.name)
            return true;
        else
            return false;
    }
    else
        return false;
}