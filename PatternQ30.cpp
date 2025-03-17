#include <iostream>
using namespace std;

int main()
{
    // i=row, j=column
    int n, i, j;
    cout << "Enter the number : ";
    cin >> n;

    // loop from 1 to n
    for (i = 1; i <= n; i++)
    {
        // print * for the first part of the row
        for (j = 1; j <= i; j++)
            cout << "* ";

        // print spaces in the middle
        for (j = 1; j <= 2 * n - 2 * i; j++)
            cout << "  ";

        // print * for the second part of the row
        for (j = 1; j <= i; j++)
            cout << "* ";

        // move to the next line
        cout << endl;
    }

    // loop from n-1 to 1
    for (i = n - 1; i >= 1; i--)
    {
        // print * for the first part of the row
        for (j = 1; j <= i; j++)
            cout << "* ";

        // print spaces in the middle
        for (j = 1; j <= 2 * n - 2 * i; j++)
            cout << "  ";

        // print * for the second part of the row
        for (j = 1; j <= i; j++)
            cout << "* ";

        // move to the next line
        cout << endl;
    }

    return 0;
}

/* Output

*                 * 
* *             * * 
* * *         * * * 
* * * *     * * * * 
* * * * * * * * * * 
* * * *     * * * * 
* * *         * * * 
* *             * * 
*                 *  

*/
