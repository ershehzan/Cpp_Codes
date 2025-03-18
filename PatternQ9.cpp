#include <iostream> // Include the input-output stream library
using namespace std; // Use the standard namespace

int main()
{
    int n, i, j; // Declare integer variables for the number of rows, and loop counters

    // Prompt the user to enter a number
    cout << "Enter the number: ";
    cin >> n; // Read the input number and store it in variable 'n'

    // Outer loop to handle the number of rows
    for (i = 1; i <= n; i++)
    {
        // Inner loop to handle the number of columns
        // This loop runs from 1 to the current row number
        for (j = 1; j <= i; j++)
        {
            cout << "* "; // Print a star followed by a space
        }
        cout << endl; // Move to the next line after printing all stars in the current row
    }
    return 0; // Return 0 to indicate successful execution
}

/* Output
Enter the number: 5
* 
* * 
* * * 
* * * * 
* * * * *    
*/
