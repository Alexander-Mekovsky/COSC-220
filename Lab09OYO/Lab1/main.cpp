#include <iostream>
#include <stack>
#include <sstream>

using namespace std;

int main()
{
    string input;
    /* int leftBrace = 0, rightBrace = 0, leftParent = 0, rightParent = 0, leftBracket = 0, rightBracket = 0;
    bool brace = false, parent = false, bracket = false; */
    cout << "Enter expression: ";
    getline(cin, input);
    stack<char> express;
    stack<char> temp;
    for(int i = 0; i < input.size(); i++)
    {
        express.push(input[i]);
    }
    int size = express.size();
    char tempChar;
    while(!express.empty())
    {
        tempChar = express.top();
        if(tempChar == '}' || tempChar == ']' || tempChar == ')')
        {
            temp.push(tempChar);
            express.pop();
        }
        else if(tempChar == '{' && temp.top() == '}')
        {
            express.pop();
            temp.pop();
        }
        else if(tempChar == '(' && temp.top() == ')')
        {
            express.pop();
            temp.pop();
        }
        else if(tempChar == '[' && temp.top() == ']')
        {
            express.pop();
            temp.pop();
        }
        else
            express.pop();
    }
    if(temp.empty())
        cout << "Delimiters are balanced." << endl;
    else
        cout << "Delimiters are not balanced." << endl;
    return 0;
}