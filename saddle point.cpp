#include <iostream>
using namespace std;

int main()
{
    int da[4][4], r, c, f=0;
    cout << "Enter the size of the array.\n";
    cin >> r >> c ;
    cout << "Enter the elements in the array.\n";
    for(int i = 0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            cin>> da[i][j];
        }
    }
    //Saddle Point Finding.
    int mi, ma, x, y,k;
    for(int i = 0; i<r; i++)
    {
        mi = da[i][0];
        y = 0;
        for(int j=0; j<c; j++)
        {
            if(mi>da[i][j])
            {
                mi = da[i][j];
                x = i;
                y = j;
            }
        }
        ma = da[0][y];
        for( k = 0; k<r; k++)
        {
            if(ma < da[k][y])
            {
                ma = da[k][y];
            }
        }
        if(mi == ma)
            cout << "Saddle Point :- " << ma << "\nAt Row = " << k << ", Column = " << y+1 << " .\n" ;
            f++;
    }
    if(f==0)
        cout << "No Saddle Point.\n";
    return 0;
}
