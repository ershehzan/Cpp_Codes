#include <iostream>  // Include the input-output stream library for standard I/O operations
using namespace std; // Use the standard namespace to avoid writing std:: before cin, cout

int main()
{
    int n; // Variable to store the size of the square pattern

    // Taking user input for the value of 'n'
    cin >> n;

    int row, col;  // Loop control variables for rows and columns
    int count = 1; // Counter variable to print consecutive numbers

    // Outer loop to control the number of rows
    for (row = 1; row <= n; row++)
    {
        // Inner loop to control the number of columns
        for (col = 1; col <= n; col++)
        {
            cout << count << " "; // Print the current value of 'count'
            count++;              // Increment the counter for the next number
        }
        cout << endl; // Move to the next line after completing a row
    }
    
    return 0; // Indicating successful program execution
}
