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
       tmp = new node();
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
        for(i = 0; i<pos-1 ; i++)
        {
            q = q->link;
        }
        tmp->link = q->link;
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
   void Count()
   {
       struct node *q;
       int c=0;
       q = head;
       while(q != NULL)
       {
            q = q->link;
            c++;
       }
       cout << "\nThe number of nodes :- " << c << endl;
   }
   void Search(int dt)
   {
       struct node *q;
       q = head;
       int i, data = dt, f = 0, item;
       while(q != NULL)
       {
            item = q->info;
            if(item == dt)
            {
                f++;
            }
            q = q->link;
       }
       if(f>0)
       {
           cout << "\nElement is present " << f << " time(s).\n";
       }
       else
       {
           cout << "\nElement is not present.\n";
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
   void Reverse()
   {
         struct node *current, *prev, *next ;
         current = head;
         prev = NULL;
         next = NULL;
         while(current != NULL)
         {
             next = current->link;
             current->link = prev;
             prev = current;
             current = next;
         }
         head = prev ;
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
    cout << "4. Delete node !\n";
    cout << "5. Count the no. of nodes !\n";
    cout << "6. Search an element !\n";
    cout << "7. Reverse the linked list !\n";
    cout << "8. Display !\n";
    cout << "9. Exit !\n";
    while(ch != 9)
    {
        cout << "Enter the choice :- \n";
        cin >> ch;
        switch(ch)
        {
    case 1 :
        cout << "Enter the number of nodes :- ";
        cin >> n ;
        cout << "Enter the number of elements :- \n";
        for(i = 0; i<n; i++)
        {
            cin >> ele ;
            obj.create_list(ele);
        }
        break;
    case 2 :
        cout << "\nEnter an element at the beginning :- ";
        cin >> ele ;
        obj.Add_Begin(ele);
        break;
    case 3 :
        cout << "\nEnter an element and its position :- ";
        cin >> ele >> posi ;
        obj.Add_After(ele,posi);
        break;
    case 4 :
        cout << "\nEnter a position to be deleted :- ";
        cin >> posi ;
        obj.Delete(posi);
        break;
    case 5 :
        obj.Count();
        break;
    case 6 :
        cout << "\nEnter an element to be searched :- ";
        cin >> ele ;
        obj.Search(ele);
        break;
    case 7 :
        obj.Reverse();
        break;
    case 8:
        obj.Display();
        break;
    case 9 :
        cout << "Exited !\n";
    default :
        cout << "Wrong input !\n";
    }
    }
    return 0;
}
