#include <iostream>
using namespace std;
int unique_digit(int num)
{
   int d1,d2,d3;
   d1 = num % 10;
   num/=10;
   d2 = num % 10;
   num/=10;
   d3 = num;
}
int triad(int num)
{
   if(unique_digit(num))
   {
       if(unique_digit(num*2))
       {
           if(unique_digit(num*3))
           {
               return 1;
           }
       }
   }
   else
   {
       return 0;
   }
}
int main()
{
    int num;
    cout << "Enter a 3 digit number :- ";
    cin >> num;
    if(triad(num))
    {
        cout << num << " is a triad number." << endl;
    }
    else
    {
        cout << num << " is not a triad number." << endl;
    }
    return 0;
}
