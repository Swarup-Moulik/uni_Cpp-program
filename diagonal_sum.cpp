#include<iostream>
using namespace std;

int main()
{
int a[10][10], n, sum = 0, rj, j=0;
cout << "Enter the dimension of the square matrix :- ";
cin >> n;
rj = n-1;
cout << "Enter the elements in the array :- \n";
for(int i = 0; i<n; i++)
{
for(int j = 0; j<n; j++)
{
cin >> a[i][j];
}
}
cout << "The matrix :-\n";
for(int i = 0; i<n; i++)
{
for(int j = 0; j<n; j++)
{
cout << a[i][j] << "\t";
}
cout << endl;
}
for(int i = 0; i<n; i++)
{
if(j==rj)
    sum+= a[i][j];
else
    sum+= a[i][j] + a[i][rj];

--rj;++j;
}
cout << "The sum of diagonals are :- " << sum << endl;
return 0;
}
