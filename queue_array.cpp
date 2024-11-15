#include<iostream>
using namespace std;

#define SIZE 10

class Deque
{
    int que[SIZE];
    int frnt, rear ;
public :
    Deque()
    {
        frnt = rear = -1;
    }
    void ins_rear(int dt)
    {
        if(frnt == 0 && rear == SIZE-1)
            cout << "Queue is full";
        else
        {
            if(frnt == -1)
            {
                   frnt = rear = 0;
            }
            else if(rear == SIZE-1)
            {
                rear = 0;
            }
            else
            {
                rear = rear+1 ;
            }
            que[rear] = dt;
        }
    }
    void ins_front(int dt)
    {
        if(frnt == 0 && rear == SIZE-1)
            cout << "Queue is full";
        else
        {
            if(frnt == -1)
            {
                frnt = rear = 0;
            }
            else if(frnt == 0)
            {
                frnt = SIZE-1;
            }
            else
            {
                frnt--;
            }
            que[frnt] = dt;
        }
    }
    int del_front()
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
    int del_rear()
    {
        int val;
        if(frnt == -1 && rear == -1)
        {
            cout << "Queue is empty";
            return -999;
        }
        else if(frnt == rear)
        {
            val = que[rear];
            frnt = rear = -1;
        }
        else
        {
            val = que[rear];
            rear--;
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
        if (frnt <= rear)
        {
            for(i = frnt; i <= rear; i++)
            {
                cout << que[i] << "\t";
            }
        }
        else
        {
            for(i = frnt; i < SIZE; i++)
            {
                cout << que[i] << "\t";
            }
            for(i = 0; i <= rear; i++)
            {
                cout << que[i] << "\t";
            }
        }
    }
    }
};
int main()
{
    Deque obj;
    int ele;
    int ch;
    cout << "1. Insert from front !\n";
    cout << "2. Insert from rear !\n";
    cout << "3. Delete from front !\n";
    cout << "4. Delete from rear !\n";
    cout << "5. Display !\n";
    cout << "6. Exit !\n";
    while(ch != 6)
    {
        cout << "\nEnter your choice :- ";
        cin >> ch;
        switch(ch)
        {
        case 1 :
            cout << "Enter the queue element to be inserted from front :- \n";
            cin >> ele;
            obj.ins_front(ele);
            break;
        case 2 :
            cout << "Enter the queue elements to be inserted from rear :-\n";
            cin >> ele;
            obj.ins_rear(ele);
            break;
        case 3 :
            ele = obj.del_front();
            if(ele != -999)
                cout << "Deleted element :- "  << ele << endl;
            break;
        case 4 :
            ele = obj.del_rear();
            if(ele != -999)
                cout << "Deleted element :- "  << ele << endl;
            break;
        case 5 :
            obj.display();
            break;
        case 6 :
            cout << "Exited !\n";
            break;
        default :
            cout << "Invalid input !\n";
        }
    }
    return 0;
}
