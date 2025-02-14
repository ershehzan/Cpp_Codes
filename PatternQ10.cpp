#include <iostream>
using namespace std;

int main()
{
    int n, i, j; // Declare variables for user input and loop counters

    // Prompt the user to enter a number
    cout << "Enter the number : ";
    cin >> n; // Read user input

    // Outer loop controls the number of rows
    for (i = 1; i <= n; i++)
    {
        // Inner loop prints numbers from 1 to the current row number
        for (j = 1; j <= i; j++)
        {
            cout << j << " "; // Print the current number with space
        }
        cout << endl; // Move to the next line after each row
    }

    return 0; // Indicate successful program termination
}

/* Output Example (when user enters 5)
Enter the number: 5
1         
1 2       
1 2 3     
1 2 3 4   
1 2 3 4 5  
*/
