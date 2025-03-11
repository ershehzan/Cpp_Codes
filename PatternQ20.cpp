#include <iostream>
using namespace std;

int main()
{
    int n, i, j; // Declare integer variables

    // Prompt the user to enter a number
    cout << "Enter the number : ";
    cin >> n; // Take user input and store it in 'n'

    // Outer loop controls the number of rows
    for (i = 1; i <= n; i++)
    {
        // Inner loop to print spaces before the characters
        for (j = 1; j <= n - i; j++) // (n-i) spaces to create right alignment
        {
            cout << "  "; // Print two spaces for proper formatting
        }

        // Calculate the character to be printed in the row
        char name = 'A' + (i - 1); // 'A' corresponds to ASCII 65, 'B' = 66, etc.

        // Inner loop to print characters in the pattern
        for (j = 1; j <= i; j++) // Print 'i' times on the current row
        {
            cout << name << " "; // Print character followed by space
        }

        cout << endl; // Move to the next line after completing a row
    }
    
    return 0; 
}

/* Example Output (if n = 5)

        A 
      B B 
    C C C 
  D D D D 
E E E E E 

Explanation:
- The number of rows is determined by the user input (n).
- Each row starts with spaces to create a right-aligned triangle.
- The character printed starts from 'A' for the first row and increases with each row.
- The number of characters printed on each row is equal to the row number.

Pattern formation logic:
- Row 1:  (n-1) spaces + 1 'A'
- Row 2:  (n-2) spaces + 2 'B's
- Row 3:  (n-3) spaces + 3 'C's
- ...
- Row n:  (0) spaces + n times the corresponding letter.

*/
