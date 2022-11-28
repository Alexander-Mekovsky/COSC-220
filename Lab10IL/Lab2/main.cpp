#include <iostream>
#include <string>

using namespace std;


bool isPal(const string &str, int startIndex, int endIndex)
{
    int startEnd = (endIndex + startIndex / 2) + 1;
    int endEnd = (endIndex + startIndex / 2);
    if(str[startIndex] != str[endIndex])
        return false;
    if(str[startIndex] == startEnd && str[endIndex] == endEnd)
        return true;
    if(str[startIndex] == str[endIndex])
        return true;
    return isPal(str, startIndex + 1, endIndex - 1);
}
int main()
{
    string pal;
    cout << "Enter a string, no spaces and all lower case: ";
    cin >> pal;
    int length = pal.length();
    bool status = isPal(pal, 0, length - 1);
    if(status)
        cout << pal << " is a palindrome" << endl;
    else
        cout << pal << " is not a palindrome" << endl;
    return 0;
}