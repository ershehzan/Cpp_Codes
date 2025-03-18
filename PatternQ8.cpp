#include <iostream> // Include the iostream library to use input and output functions
using namespace std; // Use the standard namespace

int main() // Main function where the execution begins
{
    // i=row    j=column
    int num; // Variable to store the number entered by the user
    // Extra variable
    int count = 1; // Variable to keep track of the sequence of numbers to be printed

    cout << "Enter a number : "; // Prompt the user to enter a number
    cin >> num; // Read the number entered by the user

    // Outer loop to handle the number of rows
    for (int i = 1; i <= num; i++)
    {
        // Inner loop to handle the number of columns
        for (int j = 1; j <= num; j++)
        {
            // Print the current count value followed by a space
            // cout << (i - 1) * 5 + j << " "; // Alternate solution (commented out)
            cout << count << " "; // Print the current value of count
            count++; // Increment the count by 1
        }
        cout << endl; // Move to the next line after printing all columns of the current row
    }

    return 0; // Return 0 to indicate successful execution
}

/* Output
1 2 3 4 5
6 7 8 9 10
11 12 13 14 15
16 17 18 19 20
21 22 23 24 25
*/
