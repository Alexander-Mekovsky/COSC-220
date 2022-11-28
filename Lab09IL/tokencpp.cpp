#include <iostream>
#include <sstream>
#include <stack>

using namespace std;

void scalc(string s, stack<string> &right)
{
    if(s == "+")
        {
            string a = right.top();
            right.pop();
            string b = right.top();
            right.pop();
            double aval = atof(a.c_str());
            double bval = atof(b.c_str());
             double newval = aval + bval;
             right.push(to_string(newval));
        }
         if(s == "-")
         {
             string a = right.top();
              right.pop();
              string b = right.top();
             right.pop();
             double aval = atof(a.c_str());
             double bval = atof(b.c_str());
             double newval = bval - aval;
              right.push(to_string(newval));
         }
         if(s == "*")
         {
             string a = right.top();
              right.pop();
              string b = right.top();
              right.pop();
              double aval = atof(a.c_str());
              double bval = atof(b.c_str());
             double newval = aval * bval;
              right.push(to_string(newval));
          }
          if(s == "/")
         {
             string a = right.top();
              right.pop();
              string b = right.top();
              right.pop();
              double aval = atof(a.c_str());
             double bval = atof(b.c_str());
              double newval = bval / aval;
              right.push(to_string(newval));
          }
}

stack<string> spostfix(stack<string> &right)
{
    while(right.size() >= 3)
    {
        string one = right.top();
        right.pop();
        if(one == "+" || one == "-" || one == "*" || one == "/")
        {
            string two = right.top();
            right.pop();
            if(two == "+" || two == "-" || two == "*" || two == "/")
            {
                scalc(two, right);
                right.push(one);
            }
            else
            {
                string three = right.top();
                right.pop();
                if(three == "+" || three == "-" || three == "*" || three == "/")
                {
                    scalc(three, right);
                    right.push(two);
                    right.push(one);
                }
                else
                {
                    right.push(three);
                    right.push(two);
                    scalc(one, right);
                }
            }
        }
    }
    return right;
}

int main()
{
    string sinput;
    cout << "Enter a stack postfix expression: ";
    getline(cin, sinput);
    stack<string> stokens;
    stringstream sinputstream(sinput);
    string stoken;
    while(getline(sinputstream, stoken, ' ')){
        stokens.push(stoken);
    }
    stack<string> stokensPF = spostfix(stokens);
    cout << "Stack Print: "; 
    while(!stokens.empty())
    {
        cout << stokens.top() << " ";
        stokens.pop();
    }
    cout << endl;
    return 0;
}