#include <iostream> 
using namespace std;
int main()
{
    int num, row, col; // Declare variables: num for user input, row and col for loops

    // Prompt the user to enter a number
    cout << "Enter a number: ";
    cin >> num; // Read user input

    // Outer loop to handle the rows (total rows = num)
    for (row = 1; row <= num; row++)
    {
        // Inner loop to handle the columns (each row will have 'num' columns)
        for (col = 1; col <= num; col++)
        {
            cout << col * col << "  "; // Print the square of column number
        }
        cout << endl; // Move to the next line after printing one row
    }

    return 0; // Indicate successful program termination
}

/* Example Output (when user enters 5)
Enter a number: 5
1  4  9  16  25      
1  4  9  16  25      
1  4  9  16  25      
1  4  9  16  25      
1  4  9  16  25      
*/

/* Explanation:
- The outer loop (row) runs from 1 to 'num', controlling the number of rows.
- The inner loop (col) runs from 1 to 'num' in each row.
- Each value printed is `col * col`, which is the square of the column number.
- After completing one row, `cout << endl;` moves to the next line.
- The result is a square pattern where each row contains squares of numbers from 1 to 'num'.
*/
