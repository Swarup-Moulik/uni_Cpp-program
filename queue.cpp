#include<iostream>
using namespace std;

#define SIZE 10

class Queue
{
    int que[SIZE];
    int frnt, rear ;
    public :
    Queue()
    {
        frnt = rear = -1;
    }
    void insrt(int dt)
    {
        if(frnt == 0 && rear == SIZE-1)
            cout << "Queue is full";
        else
        {
            if(frnt == -1)
            {
                   frnt = rear = 0;
            }
            else
            {
                rear = rear+1 ;
            }
            que[rear] = dt;
        }
    }
    int delte()
    {
        int val;
        if(frnt == -1 && rear == -1)
        {
            cout << "Queue is empty";
            return -999;
        }
        else if(frnt == rear)
        {
            val = que[frnt];
            frnt = rear = -1;
        }
        else
        {
            val = que[frnt];
            frnt = frnt + 1;
        }
        return val;
    }
    void display()
    {
    int i;
    if(frnt == -1 && rear == -1)
    {
        cout << "Queue is empty";
        return;
    }
    else
    {
        cout << "Queue elements are :- \n";
        for(i = frnt; i <= rear; i++)
        {
            cout << que[i] << "\t";
        }
        cout << endl;
    }
    }
};
int main()
{
    Queue obj;
    int ele,ch;
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
            cout << "Enter the queue element to be inserted :-\n";
            cin >> ele;
            obj.insrt(ele);
            break;
        case 2 :
            ele = obj.delte();
            if(ele != -999)
                cout << "Deleted element :- "  << ele << endl;
            break;
        case 3 :
            obj.display();
            break;
        case 4 :
            cout << "Exited !\n";
            break;
        default :
            cout << "Invalid input !\n";
        }
    }
    return 0;
}
