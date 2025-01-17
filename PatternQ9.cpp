#include <iostream>
using namespace std;
int main()
{
    int n, i, j;
    cout << "Enter the number : ";
    cin >> n;

    for (i = 1; i <= n; i++)
    {

        for (j = 1; j <= i; j++)// Loop run from 1 to no. of rows
        {
            cout << "* ";
        }
        cout << endl;
    }
        return 0;
    }
    /* Output
* 
* * 
* * * 
* * * * 
* * * * *    */