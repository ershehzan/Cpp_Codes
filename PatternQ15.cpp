#include <iostream> // Include the standard input-output stream library
using namespace std; // Use the standard namespace

int main()
{
    int i, j, n; // Declare integer variables for loops and user input
    cout << "Enter the number : "; // Prompt the user to enter a number
    cin >> n; // Take input from the user and store it in variable n
    
    // Outer loop: Controls the number of rows in the pattern
    for (i = 1; i <= n; i++)
    {
        // Inner loop: Prints decreasing numbers in each row
        // The number of numbers in each row is determined by (n - (i - 1))
        for (j = 1; j <= n - (i - 1); j++)
        {
            cout << j << " "; // Print the current number with a space
        }
        
        cout << endl; // Move to the next line after printing numbers for the current row
    }
    return 0; // Return 0 to indicate successful execution
}

/* Sample Output for n = 5
Enter the number : 5
1 2 3 4 5
1 2 3 4
1 2 3
1 2
1  */
