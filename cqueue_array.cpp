#include <iostream>
using namespace std;

#define SIZE 10

class Cque
{
    int que[SIZE];
    int frnt, rear ;
public :
    Cque()
    {
        frnt = rear = -1;
    }
    void insrt(int dt)
    {
        if((frnt == rear+1)|| (frnt == 0 && rear == SIZE-1))
            cout << "Queue is full\n";
        else
        {
            if(frnt == -1)
            {
                   frnt = rear = 0;
            }
            else
            {
                rear = (rear+1)%SIZE ;
            }
            que[rear] = dt;
        }
    }
    int dlete()
    {
        int val;
        if(frnt == -1 && rear == -1)
            cout << "Queue is empty\n";
        else if(frnt == rear)
        {
            val = que[frnt];
            frnt = rear = -1;
        }
        else
        {
            val = que[frnt];
            frnt = (frnt + 1)%SIZE ;
        }
        return val;
    }
    void display()
    {
    if (frnt == -1)
    {
        cout << "Queue is empty\n" << endl;
        return;
    }
    cout << "Queue elements are :- \n";
    if (frnt <= rear)
    {
        for (int i = frnt; i <= rear; i++)
        {
            cout << que[i] << "\t";
        }
    }
    else
    {
        for (int i = frnt; i < SIZE; i++)
        {
            cout << que[i] << "\t";
        }
        for (int i = 0; i <= rear; i++)
        {
            cout << que[i] << "\t";
        }
    }
    cout << endl;
    }
};
int main()
{
    Cque obj;
    int n,i,ele;
    int ch;
    cout << "1. Insert in the queue !\n";
    cout << "2. Delete from the queue !\n";
    cout << "3. Display !\n";
    cout << "4. Exit !\n";
    while(ch != 4)
    {
        cout << "Enter your choice :- ";
        cin >> ch;
        switch(ch)
        {
        case 1:
            cout << "Enter the element :- ";
            cin >> ele;
            obj.insrt(ele);
            break;
        case 2:
            ele = obj.dlete();
            cout << "Deleted element :- "  << ele << endl;
            break;
        case 3:
            obj.display();
            break;
        case 4:
            cout << "Exited.\n";
            break;
        default :
            cout << "Invalid input.";
        }
    }
    return 0;
}
