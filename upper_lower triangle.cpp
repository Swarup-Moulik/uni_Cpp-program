#include<iostream>
using namespace std;

int main()
{
  int n, sut, slt ;
  cout << "Enter the dimensions of the matrix :- ";
  cin >> n;
  int a[n][n];
  cout << "Enter the elements in the matrix :- \n";
  for(int i = 0; i<n; i++)
  {
    for(int j = 0; j<n ; j++)
    {
      cin >> a[i][j];
    }
  }
  cout << "The matrix is :- \n";
  for(int i = 0; i<n; i++)
  {
    for(int j = 0; j<n ; j++)
    {
      cout << a[i][j] << "\t";
    }
    cout << endl;
  }
  for(int i = 0; i<n; i++)
  {
    for(int j = i+1 ; j<n ; j++)
    {
      sut+= a[i][j];
      slt+= a[j][i];
    }
  }
  cout << "The sum of upper triangle :- " << sut << endl;
  cout << "The sum of lower triangle :- " << slt << endl;
  return 0;
}
