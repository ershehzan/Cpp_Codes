#include <iostream>
using namespace std;

int main()
{
    // i represents rows, j represents columns
    int n, i, j;
    cout << "Enter the number of rows: ";
    cin >> n;

    for (i = 1; i <= n; i++) // Loop for each row
    {
        // Print spaces to align the pyramid
        for (j = 1; j <= n - i; j++) 
        {
            cout << " "; // Adding space before stars to center-align the pattern
        }

        // Print stars in increasing order
        for (j = 1; j <= 2 * i - 1; j++) 
        {
            cout << "*"; // Printing stars to form a pyramid
        }

        cout << endl; // Move to the next line after each row
    }

    return 0;
}

/* Output for n = 5

    *
   ***
  *****
 *******
*********

*/

