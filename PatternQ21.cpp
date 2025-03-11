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
        // Inner loop to print spaces for right alignment
        for (j = 1; j <= n - i; j++) // (n-i) spaces before printing characters
        {
            cout << "  "; // Print two spaces for proper formatting
        }

        // Inner loop to print increasing characters in each row
        for (j = 1; j <= i; j++)
        {
            char name = 'A' + j - 1; // 'A' corresponds to ASCII 65, 'B' = 66, etc.
            cout << name << " "; // Print character followed by a space
        }

        cout << endl; // Move to the next line after completing a row
    }

    return 0; 
}

/* Example Output (if n = 5)

        A 
      A B 
    A B C 
  A B C D 
A B C D E 

Explanation:
- The number of rows is determined by the user input (n).
- Each row starts with spaces to create a right-aligned pattern.
- The first character printed in each row is 'A', and subsequent characters increase in order.
- The number of characters printed in each row is equal to the row number.

Pattern formation logic:
- Row 1:  (n-1) spaces + 'A'
- Row 2:  (n-2) spaces + 'A B'
- Row 3:  (n-3) spaces + 'A B C'
- ...
- Row n:  (0) spaces + 'A B C D ...' (up to nth letter)

*/
