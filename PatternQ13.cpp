#include <iostream>
using namespace std;
int main()
{
    int n, i, j;
    cout << "Enter the number : ";
    cin >> n;

    for (i = 1; i <= n; i++)
    {
        // Loop run from 1 to no. of rows 1 to j = row
        char name = 'a' + i - 1; // Calculate the starting character for the current row
        for (j = 1; j <= i; j++) // Inner loop for printing characters in the current row
        {
            cout << name << " ";
        }
        cout << endl;
    }
    return 0;
}
/* Output
a
b b
c c c
d d d d
e e e e e   */