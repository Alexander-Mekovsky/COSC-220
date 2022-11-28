#include <iostream>
#include <sstream>
#include <queue>

using namespace std;

void qcalc(string s, queue<string> &right)
{
    if(s == "+")
        {
            string a = right.front();
            right.pop();
            string b = right.front();
            right.pop();
            double aval = atof(a.c_str());
            double bval = atof(b.c_str());
             double newval = aval + bval;
             right.push(to_string(newval));
        }
         if(s == "-")
         {
             string a = right.front();
              right.pop();
              string b = right.front();
             right.pop();
             double aval = atof(a.c_str());
             double bval = atof(b.c_str());
             double newval = bval - aval;
              right.push(to_string(newval));
         }
         if(s == "*")
         {
             string a = right.front();
              right.pop();
              string b = right.front();
              right.pop();
              double aval = atof(a.c_str());
              double bval = atof(b.c_str());
             double newval = aval * bval;
              right.push(to_string(newval));
          }
          if(s == "/")
         {
             string a = right.front();
              right.pop();
              string b = right.front();
              right.pop();
              double aval = atof(a.c_str());
             double bval = atof(b.c_str());
              double newval = bval / aval;
              right.push(to_string(newval));
          }
}
queue<string> qpostfix(queue<string> &right)
{
    while(right.size() >= 3)
    {
        string one = right.front();
        right.pop();
        if(one == "+" || one == "-" || one == "*" || one == "/")
        {
            string two = right.front();
            right.pop();
            if(two == "+" || two == "-" || two == "*" || two == "/")
            {
                qcalc(two, right);
                right.push(one);
            }
            else
            {
                string three = right.front();
                right.pop();
                if(three == "+" || three == "-" || three == "*" || three == "/")
                {
                    qcalc(three, right);
                    right.push(two);
                    right.push(one);
                }
                else
                {
                    right.push(three);
                    right.push(two);
                    qcalc(one, right);
                }
            }
        }
        else
        {
            right.push(one);
        }
    }
    return right;
}

int main()
{
    string qinput;
    queue<string> qtokens;
    cout << "Enter a queue postfix expression: ";
    getline(cin, qinput);
    stringstream qinputstream(qinput);
    string qtoken;
    while(getline(qinputstream, qtoken, ' ')){
        qtokens.push(qtoken);
    }
    queue<string> qtokensPF = qpostfix(qtokens);
    cout << "Queue Print: ";
    while(!qtokens.empty())
    {
        cout << qtokens.front() << " ";
        qtokens.pop();
    }
    cout << endl;

    return 0;
}