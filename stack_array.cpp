#include <iostream>
using namespace std;

#define SIZE 10

class Stack
{
    int stck[SIZE];
    int top;
    public :
    Stack()
    {
        top = -1;
    }
    void push(int data)
    {
        if(top == SIZE-1)
        {
            cout << "Stack is full ! \n";
        }
        else
        {
            top = top + 1;
            stck[top] = data;
        }
    }
    int pop()
    {
        int item = 0;
        if(top == -1)
        {
            cout << "Stack is empty ! \n";
            return -999;
        }
        else
        {
            item = stck[top--];
        }
        return item;
    }
    void display()
    {
        int i;
        if(top == -1)
        {
            cout << "Stack is empty ! \n";
            return;
        }
        else
        {
            cout << "The stack elements are :- \n";
            for(i = top; i > -1; i--)
            {
                cout << stck[i] << endl ;
            }
        }
    }
};
    int main()
    {
        Stack obj;
        int sz, info, pn, i, pinfo;
        int ch;
        cout << "1. Insert !\n";
        cout << "2. Delete !\n";
        cout << "3. Display !\n";
        cout << "4. Exit !\n";
        while(ch != 4)
        {
            cout << "Enter your choice :- ";
            cin >> ch;
            switch(ch)
            {
            case 1:
                cout << "Enter the element in the stack :- \n";
                cin >> info;
                obj.push(info);
                break;
            case 2:
                pinfo = obj.pop();
                if(pinfo!= -999)
                    cout << "Popped data :- " << pinfo << endl;
                break;
            case 3:
                obj.display();
                break;
            case 4:
                cout << "Exited !";
                break;
            default :
                cout << "\nInvalid entry .\n";
            }
        }
        return 0;
    }

