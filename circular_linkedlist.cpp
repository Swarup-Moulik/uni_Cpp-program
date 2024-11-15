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
   void ins_front(int n)
   {
     struct node *q, *tmp;
     tmp = (struct node*)new(struct node);
     tmp->info = n;
     tmp->link = head;
     head = tmp;
     if (last == NULL)
     {
        last = head;
     }
     last->link = head;
   }
   void ins_rear(int n)
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
   int del_front()
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
   int del_rear()
   {
     int ele;
     if(head == NULL)
     {
        return -999;
     }
     else
     {
       struct node *q, *tmp;
       q = head;
       while(q->link != last)
       {
         q = q->link;
       }
       ele = q->link->info;
       tmp = last;
       last = q;
       last->link = head;
       tmp = NULL;
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
          cout << b->info << "\t";
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
    cout << "1. Insert in the front !\n";
    cout << "2. Insert at the end !\n";
    cout << "3. Delete from the front !\n";
    cout << "4. Delete from the end !\n";
    cout << "5. Display !\n";
    cout << "6. Exit !\n";
    while(ch != 6)
    {
        cout << "Enter your choice :- ";
        cin >> ch;
        switch(ch)
        {
        case 1:
            cout << "Enter the element in the front :- ";
            cin >> ele;
            obj.ins_front(ele);
            break;
        case 2:
            cout << "Enter the element at the end :- ";
            cin >> ele;
            obj.ins_rear(ele);
            break;
        case 3:
            ele = obj.del_front();
            if(ele == -999)
                cout << "Linked List is empty.\n";
            else
                cout << "Deleted element :- "  << ele << endl;
            break;
        case 4:
            ele = obj.del_rear();
            if(ele == -999)
                cout << "Linked List is empty.\n";
            else
                cout << "Deleted element :- "  << ele << endl;
            break;
        case 5:
            obj.display();
            break;
        case 6:
            cout << "Exited.\n";
            break;
        default :
            cout << "Invalid input.\n";
        }
    }
}
