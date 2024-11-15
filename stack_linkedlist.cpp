1#include<iostream>
using namespace std;

class Stack_LL
{
    struct node
    {
        int info;
        struct node *link;
    };
    struct node *top;
public:
   Stack_LL()
   {
     top = NULL ;
   }
   void push(int dt)
   {
        struct node *tmp;
        tmp = (struct node*)new(struct node);
        tmp->info = dt;
        tmp->link = top;
        top = tmp;
   }
   int pop()
   {
        struct node *tmp;
        int ele;
        tmp = top;
        if(tmp == NULL)
        {
            return -999;
        }
        ele = tmp->info;
        top = top->link;
        return ele;
   }
   void display()
   {
       struct node *q;
       cout << "Elements in stack are :- \n" ;
       q = top;
       while(q != NULL)
       {
            cout << q->info << "\n" ;
            q = q->link;
       }
   }
};
int main()
{
    Stack_LL obj;
    int i, ele;
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
                cin >> ele;
                obj.push(ele);
                break;
            case 2:
                ele = obj.pop();
                if(ele == -999)
                    cout << "Stack is empty.\n";
                else
                    cout << "Popped data :- " << ele << endl;
                break;
            case 3:
                obj.display();
                break;
            case 4:
                cout << "\nExited !";
                break;
            default :
                cout << "\nInvalid entry .";
            }
        }
}
