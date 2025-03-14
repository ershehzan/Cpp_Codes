#include <iostream>
using namespace std;

int main()
{
    // i represents the row, j represents the column
    int n, i, j;
    cout << "Enter the number of rows: ";
    cin >> n;

    // Loop to control the number of rows
    for (i = 1; i <= n; i++)
    {
        // Print spaces before the stars to align the pyramid
        for (j = 1; j <= n - i; j++)
            cout << " ";

        // Print stars with spaces for proper formatting
        for (j = 1; j <= i; j++)
            cout << "* ";

        // Move to the next line after each row is printed
        cout << endl;
    }

    return 0;
}

/* 
Expected Output (for n = 5):

    * 
   * * 
  * * * 
 * * * * 
* * * * * 

This pattern is known as a right-aligned half-pyramid.
*/
