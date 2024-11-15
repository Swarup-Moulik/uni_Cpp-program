#include<iostream>
using namespace std ;

class Linked_list
{
    struct node
    {
        int info;
        struct node *link;
    };
    struct node *head;
public:
   Linked_list()
   {
     head = NULL ;
   }
   void create_list(int dt)
   {
       struct node *q, *tmp;
       tmp = (struct node*)new(struct node);
       tmp->info = dt;
       tmp->link = NULL;
       if(head == NULL)
       {
           head = tmp;
       }
       else
       {
           q = head;
           while(q->link != NULL)
           {
               q = q->link;
           }
           q->link = tmp;
       }
   }
   void Add_Begin(int dt)
   {
       struct node *tmp;
       tmp = (struct node*)new(struct node);
       tmp->info = dt;
       tmp->link = head ;
       head = tmp;
   }
   void Add_After(int dt, int pos)
   {
        struct node *tmp, *q;
        int i;
        q = head ;
        tmp = (struct node*)new(struct node);
        tmp->info = dt;
        tmp->link = NULL;
        for(i = 1; i<pos-1 ; i++)
        {
            q = q->link;
        }
        tmp->link = q->link;
        q->link = tmp;
   }
   void Add_End(int dt)
   {
        struct node *tmp, *q;
        int i;
        q = head ;
        tmp = (struct node*)new(struct node);
        tmp->info = dt;
        tmp->link = NULL;
        while(q->link != NULL)
        {
            q = q->link;
        }
        q->link = tmp;
   }
   void Delete(int pos)
   {
       struct node *q, *tmp;
       int c=1;
       q = head;
       tmp = q;
       if(pos == 1)
       {
           head = head->link;
       }
       else
       {
           while(c<pos && c>=1)
           {
            tmp = q;
            q = q->link;
            c = c+1;
           }
            tmp->link = q->link;
            q->link = NULL;
            tmp = q = NULL;
       }
   }
   void Delete_End()
   {
       struct node *tmp, *t;
       int ele;
       tmp = head;
       if(tmp == NULL)
       {
           cout << "Linked list is empty !\n";
       }
       else
       {
           while(tmp->link->link != NULL)
           {
               tmp = tmp->link;
           }
           t = tmp->link;
           ele = t->info;
           tmp->link = NULL;
           t = NULL;
           cout << "Deleted element :- " << ele << endl;
       }
   }
   void Display()
   {
       struct node *q;
       q = head;
       if(q == NULL)
       {
           cout << "Linked list is empty !\n";
       }
       else
       {
           cout << "Elements in linked list are :- \n" ;
           while(q != NULL)
           {
                cout << q->info << "\t" ;
                q = q->link;
           }
       }
       cout << "\n";
   }
   void Count()
   {
       struct node *q;
       int c = 0, sum = 0;
       q = head;
       while(q != NULL)
       {
            sum+= q->info;
            q = q->link;
            c++;
       }
       cout << "The number of nodes :- " << c << endl;
       cout << "The sum of all nodes :- " << sum << endl;
   }
};
int main()
{
    Linked_list obj;
    int i, ele, posi, n;
    int ch;
    cout << "1. Create !\n";
    cout << "2. Add Begin !\n";
    cout << "3. Add Anywhere !\n";
    cout << "4. Add End !\n";
    cout << "5. Delete Anywhere !\n";
    cout << "6. Delete End !\n";
    cout << "7. Display !\n";
    cout << "8. Count and sum all the nodes !\n";
    cout << "9. Exit !\n";
    while(ch != 8)
    {
        cout << "Enter the choice :- ";
        cin >> ch;
        switch(ch)
        {
    case 1 :
        cout << "Enter the element :- ";
        cin >> ele ;
        obj.create_list(ele);
        break;
    case 2 :
        cout << "Enter an element at the beginning :- ";
        cin >> ele ;
        obj.Add_Begin(ele);
        break;
    case 3 :
        cout << "Enter an element and its position :-  \n";
        cin >> ele >> posi ;
        obj.Add_After(ele,posi);
        break;
    case 4 :
        cout << "Enter the element at the end :- ";
        cin >> ele ;
        obj.Add_End(ele);
        break;
    case 5 :
        cout << "Enter the position to be deleted :-  \n";
        cin >> posi ;
        obj.Delete(posi);
        break;
    case 6 :
        obj.Delete_End();
        break;
    case 7:
        obj.Display();
        break;
    case 8:
        obj.Count();
        break;
    case 9 :
        cout << "Exited !\n";
        break;
    default :
        cout << "Wrong input !\n";
    }
    }
    return 0;
}
