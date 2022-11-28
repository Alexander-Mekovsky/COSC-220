#include <iostream> 
#include <sstream>
#include <stack>

#include "ListCollection.h"

using namespace std; 

ListCollection<string> postfix(ListCollection<string> &right)
{   
    while(right.size() > 1)
    {
		/* string a  = right.popBack();
    	string b = right.popBack();
        string check = right.popBack();
        if(check == "+")
        {
            double aval = atof(a.c_str());
            double bval = atof(b.c_str());
            double val = aval + bval;
        	right.pushBack(to_string(val));
        }
        if(check == "-")
        {
            double aval = atof(a.c_str());
            double bval = atof(b.c_str());
            double val = aval - bval;
        	right.pushBack(to_string(val));
        }
        if(check == "*")
        {
            double aval = atof(a.c_str());
            double bval = atof(b.c_str());
            double val = aval * bval;
        	right.pushBack(to_string(val));
        }
       	if(check == "/")
        {
            double aval = atof(a.c_str());
            double bval = atof(b.c_str());
            double val = aval / bval;
        	right.pushBack(to_string(val));
        }
        else
        {
            right.pushBack(a);
            right.pushBack(b);
            right.pushBack(check);
        } */
        string a = right.popBack();
        if(a == "+")
        {
            string b = right.popBack();
            double aval = atof(b.c_str());
            string c = right.popBack();
            double bval = atof(c.c_str());
            double num = (aval + bval);
            right.pushBack(to_string(num));
        }
        else if(a == "-")
        {
            string b = right.popBack();
            double aval = atof(b.c_str());
            string c = right.popBack();
            double bval = atof(c.c_str());
            double num = (aval - bval);
            right.pushBack(to_string(num));
        }
        else if(a == "*")
        {
            string b = right.popBack();
            double aval = atof(b.c_str());
            string c = right.popBack();
            double bval = atof(c.c_str());
            double num = (aval * bval);
            right.pushBack(to_string(num));
        }
        else if(a == "/")
        {
            string b = right.popBack();
            double aval = atof(b.c_str());
            string c = right.popBack();
            double bval = atof(c.c_str());
            double num = (aval / bval);
            right.pushBack(to_string(num));
        }
        else
        {
            right.pushFront(a);
        }
	}
    return right;
}

int main() 
{ 
    // string input = "234 32 + 7 *";
	// Must have spaces between tokens.
 
	string input;
    cout << "Enter a postfix expression: ";
    getline(cin, input);
    
    ListCollection<string> tokens; 
    stringstream inputstream(input); 
    string token; 
    
    // Tokenizing w.r.t. space ' ' 
    while(getline(inputstream, token, ' ')) 
        tokens.pushFront(token);
      
    // Printing the token vector 
     for(int i = 0; i < tokens.size(); i++) 
        cout << tokens.getElement(i) << endl;
    ListCollection<string> newTokens = postfix(tokens);
    cout << "Value = " << tokens.popFront();
    return 0;
}
