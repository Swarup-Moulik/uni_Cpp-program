#include<iostream>
using namespace std ;

class cque_cll
{
    struct node
    {
        int info;
        struct node *link;
    };
    struct node *head, *last;
public:
   cque_cll()
   {
     head = NULL ;
     last = NULL ;
   }
   void enqueue(int n)
   {
           struct node *q, *tmp;
           tmp = (struct node*)new(struct node);
           tmp->info = n;
           tmp->link = NULL;
           if(head == NULL)
           {
                head = tmp;
                last = tmp;
           }
           else
           {
               last->link = tmp;
               last = tmp;
           }
       last->link = head;
   }
   int dequeue()
   {

       int ele;
       if(head == NULL)
       {
           return -999;
       }
       else
       {
           ele = head->info;
           if(head != last)
            {
                head = head->link;
                last->link = head;
            }
           else if(head == last)
            {
                last = NULL;
                head = NULL;
            }
           return ele;
       }
   }
   void display()
   {
      struct node *b;
      b = head;
      if(b == NULL)
      {
          cout << "Queue is empty.\n";
          return;
      }
      else
      {
        cout << "The circular queue elements are :- \n";
        while(b->link != head)
        {
          cout << b->info << endl;
          b = b->link;
        }
        cout << b->info << endl;
      }
   }
};
int main()
{
    cque_cll obj;
    int ele,ch;
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
            obj.enqueue(ele);
            break;
        case 2:
            ele = obj.dequeue();
            if(ele == -999)
                cout << "Queue is empty.\n";
            else
                cout << "Deleted element :- "  << ele << endl;
            break;
        case 3:
            obj.display();
            break;
        case 4:
            cout << "Exited.\n";
            break;
        default :
            cout << "Invalid input.\n";
        }
    }
}
