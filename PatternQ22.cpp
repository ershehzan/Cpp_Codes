#include <iostream> 
using namespace std;

int main(){
    // i represents the row, j represents the column
    int n, i, j;
    
    // Prompt the user to enter a number
    cout << "Enter the number : ";
    cin >> n; // Take user input and store it in 'n'

    // Outer loop to control the number of rows
    for (i = 1; i <= n; i++)
    {
        // Inner loop to print spaces before the stars
        for (j = 1; j <= n - i; j++) // (n-i) spaces to align the pattern to the right
        {
            cout << "  "; // Print two spaces for proper formatting
        }

        // Inner loop to print stars
        for (j = 1; j <= i; j++)
        {
            cout << "* "; // Print a star followed by a space
        }

        cout << endl; // Move to the next line after completing a row
    }

    return 0; 
}
/* Example Output (if n = 5)

        * 
      * * 
    * * * 
  * * * * 
* * * * * 

Explanation:
- The number of rows is determined by the user input (n).
- Each row starts with spaces to create a right-aligned triangle.
- The number of stars printed on each row is equal to the row number.

Pattern formation logic:
- Row 1:  (n-1) spaces + 1 '*'
- Row 2:  (n-2) spaces + 2 '*'
- Row 3:  (n-3) spaces + 3 '*'
- ...
- Row n:  (0) spaces + n '*'

*/


