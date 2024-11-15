#include<iostream>
#include<string>
using namespace std;

int main()
{
  string ini, fin = "";
  int i = 0, len;
  cout << "Enter a string :- ";
  getline(cin, ini);
  len = ini.length();
  while(i < len)
  {
    if(ini[i] != 32)
    {
      fin = fin + ini[i];
      i++;
    }
    else
    {
      fin = fin + " ";
      while(ini[i] == ' ')
      {
        i++;
      }
    }
  }
  cout << "Final string :- " << fin << endl;
  return 0;
}
