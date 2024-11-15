#include<iostream>
using namespace std;

int bin_search(int ar[], int sn, int low, int high)
{
  while(low<=high)
  {
    int mid = low+(high-low)/2;
    if(ar[mid] == sn)
    {
      return mid;
    }
    else if(ar[mid] < sn)
    {
      low = mid+1;
    }
    else
    {
      high = mid-1;
    }
  }
  return -1;
}
int main()
{
  int arr[100],n,s,rv;
  cout << "Enter the size of array :- ";
  cin >> s;
  cout << "Enter the elements in the array in ascending order :- \n";
  for(int i = 0; i<s; i++)
  {
     cin >> arr[i];
  }
  cout << "Enter the number to be searched :- ";
  cin >> n;
  rv = bin_search(arr,n,0,s-1);
  if(rv != -1)
  {
    cout << "Element is present at "<<rv<<" index.\n";
  }
  else
  {
    cout << "Element is not present. \n";
  }
  return 0;
}
