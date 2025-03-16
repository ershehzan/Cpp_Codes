#include <iostream>
using namespace std;

int main()
{
    // i = row index, j = column index
    int n, i, j;
    cout << "Enter the number: ";
    cin >> n;

    // Loop for each row (inverted pyramid)
    for (i = n; i >= 1; i--)
    {
        // Printing leading spaces
        for (j = 1; j <= n - i; j++)
            cout << "  "; // Two spaces for proper alignment

        // Printing stars in decreasing order
        for (j = 1; j <= 2 * i - 1; j++)
            cout << "* ";

        cout << endl; // Move to the next line after printing each row
    }

    return 0;
}

/* Output when n = 5:

* * * * * * * * *    
  * * * * * * *      
    * * * * *        
      * * *          
        *            

*/
