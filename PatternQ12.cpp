#include <iostream> // Include input-output stream library
using namespace std; // Use the standard namespace

int main()
{
    int n, i, j; // Declare variables: n for user input, i and j for loops

    // Prompt the user to enter a number
    cout << "Enter the number : ";
    cin >> n; // Read user input

    // Outer loop: Controls the number of rows (runs from 1 to n)
    for (i = 1; i <= n; i++)
    {
        // Inner loop: Prints numbers in decreasing order from 'i' to 1
        for (j = i; j >= 1; j--)
        {
            cout << j << " "; // Print the current value of 'j' with a space
        }
        cout << endl; // Move to the next line after printing one row
    }

    return 0; // Indicate successful program termination
}

/* Example Output (when user enters 5)
Enter the number: 5
1 
2 1 
3 2 1 
4 3 2 1 
5 4 3 2 1    
*/

/* Explanation:
- The **outer loop (i)** runs from 1 to 'n', determining the number of rows.
- The **inner loop (j)** starts from 'i' and counts **backward to 1**, printing numbers in reverse order.
- After printing one row, `cout << endl;` moves to the next line.
- This results in a right-angled triangle pattern where:
  - Row 1 prints `1`
  - Row 2 prints `2 1`
  - Row 3 prints `3 2 1`
  - ...
  - Row n prints `n (n-1) (n-2) ... 1`
*/

