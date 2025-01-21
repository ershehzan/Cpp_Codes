#include <iostream>
using namespace std;
int main()
{
    // i=row   j=column
    int n, i, j;
    cout << "Enter the number : ";
    cin >> n;
    // loop 1 to n
    for (i = 1; i <= n; i++)
    {
        // print *
        for (j = 1; j <= i; j++)
            cout << "* ";

        // print space
        for (j = 1; j <= 2 * n - 2 * i; j++)
            cout << "  ";

        // print *
        for (j = 1; j <= i; j++)
            cout << "* ";

        cout << endl;
    }
    // loop n-1 to 1
    for (i = n - 1; i >= 1; i--)
    {
        // print *
        for (j = 1; j <= i; j++)
            cout << "* ";

        // print space
        for (j = 1; j <= 2 * n - 2 * i; j++)
            cout << "  ";

        // print *
        for (j = 1; j <= i; j++)
            cout << "* ";

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