#include<iostream>
#include<string>
using namespace std;

string ones[] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
string teens[] = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
string tens[] = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

string ToWords(long num)
{
    if (num < 10)
    {
        return ones[num];
    }
    else if (num < 20)
    {
        return teens[num - 10];
    }
    else if (num < 100)
    {
        return tens[num / 10] + " " + ones[num % 10];
    }
    else if (num < 1000)
    {
        return ones[num / 100] + " Hundred " + ToWords(num % 100);
    }
    else if (num < 100000)
    {
        return ToWords(num / 1000) + " Thousand " + ToWords(num % 1000);
    }
    else if (num < 10000000)
    {
        return ToWords(num / 100000) + " Lakh " + ToWords(num % 100000);
    }
    else
    {
        return ToWords(num / 10000000) + " Crore " + ToWords(num % 10000000);
    }
}

int main()
{
  long amt;
  cout<< "Enter the number :- ";
  cin >> amt;
  cout << ToWords(amt) << endl;
  return 0;
}
