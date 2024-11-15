#include<iostream>
using namespace std;

void inssort(int a[],int s)
{
  int key, j = 0;
  for(int i = 1; i<s; i++)
  {
      key = a[i];
      j = i - 1;
      while (j>=0 && a[j>key])
      {
          a[j+1] = a[j];
          j = j-1;
      }
      a[j+1] = key;
  }
}

int bins(int a[], int l, int r, int sn)
{
  int mid = l + (r-l)/2;
  while(l < r)
  {
    if(sn == a[mid])
    {
         return mid;
    }
    else if(sn > a[mid])
    {
        l = mid+1;
    }
    else
    {
        r = mid-1;
    }
  }
  return -1;
}

int main()
{
  int a[10] = {10,5,81,33,105,27,56,79,8,11};
  inssort(a, 10);
  int s1 = 80, s2 = 27, r1, r2;
  r1 = bins(a,0,9,s1);
  if(r1 > -1)
    cout << "Number found at "<< r1 <<"th index.\n";
  else
    cout << "Number not found.\n";
  r2 = bins(a,0,9,s2);
  if(r2 > -1)
    cout << "Number found at "<< r2 <<"th index.\n";
  else
    cout << "Number not found.\n";
  return 0;
}
