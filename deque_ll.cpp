#include<iostream>
using namespace std ;

class dqueue_ll
{
    struct node
    {
    int data;
    struct node *next;
    struct node *prev;
    };
    struct node *head;
public:
   dqueue_ll()
   {
     head = NULL ;
   }
void insertFront(int data)
{
    struct node *newNode;
    newNode = (struct node*)new(struct node);
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        newNode->next = head;
        newNode->prev = NULL;
        head->prev = newNode;
        head = newNode;
    }
}
void insertRear(int data)
{
    struct node *newNode, *q ;
    newNode = (struct node*)new(struct node);
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    q = head;
    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        while(q->next != NULL)
        {
            q = q->next;
        }
        q->next = newNode;
        newNode->prev = q;
    }
}
int deleteFront()
{
    if (head == NULL)
    {
        cout << "Queue is empty.\n";
        return -999;
    }
    struct node *x;
    x = head;
    int ele = x->data;
    head = x->next;
    if (head != NULL)
        x = x->next;
    x->prev = NULL;
    return ele;
}
int deleteRear()
{
    if (head == NULL)
    {
        cout << "Queue is empty.\n";
        return -999;
    }
    struct node *x, *y;
    x = head;
    while(x->next != NULL)
    {
        x = x->next;
    }
    y = x->prev;
    int ele = x->data;
    if (y != NULL)
    {
        y->next = NULL;
    }
    else
    {
        head = NULL;
    }
    return ele;
}
void display()
{
    struct node *q;
    q = head;
    if(q == NULL)
    {
        cout << "Queue is empty.\n";
    }
    else
    {
        cout << "The queue elements are :- \n";
        while(q != NULL)
        {
            cout << q->data << endl;
            q = q->next;
        }
    }

}
};
int main()
{
    dqueue_ll obj;
    int ch,ele;
    cout << "1. Insert from front !\n";
    cout << "2. Insert from rear !\n";
    cout << "3. Delete from front !\n";
    cout << "4. Delete from rear !\n";
    cout << "5. Display !\n";
    cout << "6. Exit !\n";
    while(ch != 6)
    {
        cout << "Enter your choice :- ";
        cin >> ch;
        switch(ch)
        {
        case 1 :
            cout << "Enter the queue element to be inserted from front :- \n";
            cin >> ele;
            obj.insertFront(ele);
            break;
        case 2 :
            cout << "Enter the queue elements to be inserted from rear :-\n";
            cin >> ele;
            obj.insertRear(ele);
            break;
        case 3 :
            ele = obj.deleteFront();
            if(ele != -999)
              cout << "Deleted element :- "  << ele << endl;
            break;
        case 4 :
            ele = obj.deleteRear();
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
