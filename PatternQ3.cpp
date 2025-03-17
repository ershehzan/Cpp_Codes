#include <iostream> // Include the input-output library
using namespace std;

int main() 
{
    int n, row, col; // Declare variables to store the size of the pattern (n), and loop counters for rows and columns
    cout << "Enter a number :"; // Ask the user to enter a number for the size of the pattern
    cin >> n; // Read the number entered by the user

    // Outer loop to handle the rows
    for (row = 1; row <= n; row++) 
    {
        // Nested loop to handle the columns within each row
        for (col = 1; col <= n; col++) 
        {
            cout << col << " "; // Print the column number, followed by a space
        }
        cout << endl; // After completing a row, move to the next line
    }

    return 0; // Return 0 to indicate successful execution
}

/* Output:
1 2 3 4 5 
1 2 3 4 5 
1 2 3 4 5 
1 2 3 4 5 
1 2 3 4 5 
*/
