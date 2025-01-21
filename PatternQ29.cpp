#include <iostream>
using namespace std;
int main()
{
    // i=row   j= column
    int n, i, j;
    cout << "Enter the number : ";
    cin >> n;
    // opp loop from n to 1
    for (i = n; i >= 1; i--)
    {
        // * print
        for (j = 1; j <= i; j++)
            cout << "* ";

        // space print
        for (j = 1; j <= 2 * n - 2 * i; j++)
            cout << "  ";

        // * print
        for (j = 1; j <= i; j++)
            cout << "* ";

        cout << endl;
    }
    // opp loop from 1 to n
    for (i = 1; i <= n; i++)
    {
        // * print
        for (j = 1; j <= i; j++)
            cout << "* ";

        // space print
        for (j = 1; j <= 2 * n - 2 * i; j++)
            cout << "  ";

        // * print
        for (j = 1; j <= i; j++)
            cout << "* ";

        cout << endl;
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