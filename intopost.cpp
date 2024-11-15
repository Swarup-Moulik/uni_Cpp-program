#include <iostream>
#include <string>
using namespace std;

#define SIZE 100

class Stack
{
    string sarr[SIZE];
    int top;
public :
    Stack()
    {
        top = 0;
        sarr[top] = "(";
    }
    void push(string chr)
    {
        if(top == SIZE-1)
        {
            cout << "Stack is full ! \n";
        }
        else
        {
            top = top + 1;
            sarr[top] = chr;
        }
    }
    string pop()
    {
        string chr = "";
        if(top == -1)
        {
            cout << "Stack is empty ! \n";
        }
        else
        {
            chr = sarr[top];
            top--;
        }
        return chr;
    }
    string check()
    {
        return sarr[top];
    }
};

int main()
{
    Stack obj;
    string is, fs = "";
    string c;
    int i, len;
    cout << "Enter the expression :-";
    cin >> is;
    len = is.length();
    for(i = 0; i<len; i++)
    {
        c = is.substr(i, 1);
        if((c >= "A" && c<= "Z") || (c >= "a" && c<= "z"))
        {
            fs = fs + c;
        }
        else if(c == "(")
        {
            obj.push(c);
        }
        else if(c == ")")
        {
            string data = obj.pop();
            while(data != "(")
            {
                fs = fs + data;
                data = obj.pop();
            }
        }
        else if(c == "+" || c == "-")
        {
            string prel = obj.check();
            string popel ;
            if(prel == "*" || prel == "/" || prel == "^")
            {
                popel = obj.pop();
                fs = fs + popel;
            }
            obj.push(c);
        }
        else if(c == "*" || c == "/")
        {
            string prel = obj.check();
            string popel ;
            if(prel == "^")
            {
                popel = obj.pop();
                fs = fs + popel;
            }
            obj.push(c);
        }
        else if(c == "^")
        {
            obj.push(c);
        }
    }
    while(obj.check() != "(")
    {
        fs = fs + obj.pop();
    }
    cout<<"\nThe final string :- " << fs << endl;
    return 0;
}
