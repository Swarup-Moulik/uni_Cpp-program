#include<iostream>
using namespace std;

int lins(int a[],int as,int sn)
{
  for(int i = 0; i<10; i++)
  {
    if(sn == a[i])
    {
        return i ;
    }
  }
  return -1;
}

int main()
{
  int a[10] = {10,5,81,33,105,27,56,79,8,11};
  int s1 = 80, s2 = 27, r1, r2;
  r1 = lins(a,10,s1);
  if(r1 > -1)
    cout << "Number found at "<< r1 <<"th index.\n";
  else
    cout << "Number not found.\n";
  r2 = lins(a,10,s2);
  if(r2 > -1)
    cout << "Number found at "<< r2 <<"th index.\n";
  else
    cout << "Number not found.\n";
  return 0;
}
