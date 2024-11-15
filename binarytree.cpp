#include<iostream>
using namespace std;

struct Node
{
  int data;
  Node* left;
  Node* right;
};
Node* createnode(int dt)
{
  Node* newNode = new Node();
  newNode->data = dt;
  newNode->left = newNode->right = NULL;
  return newNode;
}
Node* insert(Node* root, int dt)
{
  if(root == NULL)
  {
    root = createnode(dt);
    return root;
  }
  if(dt<root->data)
  {
    root->left = insert(root->left,dt);
  }
  else if(dt>root->data)
  {
    root->right = insert(root->right,dt);
  }
  return root;
}
Node* inorder(Node* root)
{
  if(root!= NULL)
  {inorder(root->left);
  cout<<root->data<<"\t";
  inorder(root->right);}
}
bool search(Node* root, int sn)
{
  if(root == NULL)
  {
    return false;
  }
  if(root->data == sn)
  {
    return true;
  }
  if( sn > root->data)
  {
    return search(root->right,sn);
  }
  else if(sn<root->data)
  {
    return search(root->left,sn);
  }
}
Node* findmin(Node* root)
{
  while(root->left != NULL)
  {
    root = root->left;
  }
  return root;
}
Node* deletenode(Node* root, int dn)
{
  if(root == NULL)
  {
    return root;
  }
  if(dn < root->data)
  {
    root->left = deletenode(root->left, dn);
  }
  else if(dn > root->data)
  {
    root->right = deletenode(root->right, dn);
  }
  else
  {
    if(root->left == NULL)
    {
      Node* temp = root->right;
      delete root;
      return temp;
    }
    else if(root->right == NULL)
    {
      Node* temp = root->left;
      delete root;
      return temp;
    }
    Node* temp = findmin(root->right);
    root->data = temp->data;
    root->right = deletenode(root->right, temp->data);
  }
  return root;
}
int main()
{
  Node* root = NULL;
  int ch;
  cout << " 1. Insert " << endl;
  cout << " 2. Search " << endl;
  cout << " 3. Delete " << endl;
  cout << " 4. Inorder traversal " << endl;
  cout << " 5. Exit " << endl;
  while(ch != 5)
  {
    cout << "Enter choice :- ";
    cin >> ch;
    switch(ch)
    {
      case 1 :
       int dt;
       cout << "Enter the data :- ";
       cin>>dt;
       root = insert(root, dt);
       break;
      case 2 :
       int sn;
       cout << "Enter the number to be searched :- " ;
       cin >> sn;
       if(search(root,sn))
         cout << sn << " is present in binary tree. " << endl;
       else
         cout << sn << " is not preseent in the binary tree. " << endl;
       break;
      case 3 :
        int dn;
        cout << "Enter the number to be deleted :- ";
        cin >> dn;
        root = deletenode(root,dn);
        break;
      case 4 :
        inorder(root);
        cout << endl;
        break;
      case 5 :
        cout << "Exited.\n";
        break;
      default :
        cout << "Wrong input." << endl;
        break;
    }
  }
  return 0;
}
