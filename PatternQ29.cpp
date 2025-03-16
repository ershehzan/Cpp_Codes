#include <iostream>
using namespace std;

int main()
{
    // i = row index, j = column index
    int n, i, j;
    cout << "Enter the number: ";
    cin >> n;

    // Upper half of the pattern (from n to 1)
    for (i = n; i >= 1; i--)
    {
        // Printing left side stars
        for (j = 1; j <= i; j++)
            cout << "* ";

        // Printing spaces in the middle
        for (j = 1; j <= 2 * n - 2 * i; j++)
            cout << "  "; // Two spaces for proper alignment

        // Printing right side stars
        for (j = 1; j <= i; j++)
            cout << "* ";

        cout << endl; // Move to the next line after printing each row
    }

    // Lower half of the pattern (from 1 to n)
    for (i = 1; i <= n; i++)
    {
        // Printing left side stars
        for (j = 1; j <= i; j++)
            cout << "* ";

        // Printing spaces in the middle
        for (j = 1; j <= 2 * n - 2 * i; j++)
            cout << "  "; // Two spaces for proper alignment

        // Printing right side stars
        for (j = 1; j <= i; j++)
            cout << "* ";

        cout << endl; // Move to the next line after printing each row
    }

    return 0;
}

/* Output

* * * * * * * * * * * * * * * * 
* * * * * * *     * * * * * * * 
* * * * * *         * * * * * * 
* * * * *             * * * * * 
* * * *                 * * * * 
* * *                     * * * 
* *                         * * 
*                             * 
*                             * 
* *                         * * 
* * *                     * * * 
* * * *                 * * * * 
* * * * *             * * * * * 
* * * * * *         * * * * * * 
* * * * * * *     * * * * * * * 
* * * * * * * * * * * * * * * * 

   */
