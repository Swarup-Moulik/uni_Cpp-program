#include<iostream>
using namespace std;

void display (int ar[],int n)
{
    for(int i = 0; i<n; i++)
    {
        cout << ar[i] << "\t";
    }
    cout << endl;
}
int main()
{
    int s;
    cout << "Enter the size of the array :- ";
    cin >> s;
    int arr[s], pos;
    cout << "Enter the elements in the array :- \n";
    for(int i = 0; i < s; i++)
    {
        cin >> arr[i];
    }
    cout << "Array :- \n";
    display(arr,s);
    cout << "Enter the position to be deleted :- ";
    cin >> pos;
    for(int i = pos-1; i<s-1; i++)
    {
        arr[i] = arr[i+1];
    }
    --s;
    cout << "Array after deletion :- \n";
    display(arr,s);
    return 0;
}
