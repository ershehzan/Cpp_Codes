#include <iostream>
using namespace std;

int main()
{
    int i, j, n;
    cout << "Enter the number : ";
    cin >> n;
    for (i = 1; i <= n; i++)
    {
        // Inner loop to print decreasing number of stars in each row
        for (j = 1; j <= n-(i-1); j++)
        {
            cout <<"* ";
        }
        cout << endl; // Move to the next line after printing stars for the current row
    }
    return 0;
}
/* Output
* * * * * 
* * * * 
* * * 
* * 
*     */