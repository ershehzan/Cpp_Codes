#include <iostream>  // Include the standard input-output stream library
using namespace std; // Use the standard namespace

int main() {
    // i=row    j=column
    int n;  // Declare an integer variable 'n' to store the number of rows

    cout << "Enter a number :";  // Prompt the user to enter a number
    cin >> n;  // Read the input number and store it in 'n'

    // Loop from 1 to 'n' to iterate over each row
    for (int i = 1; i <= n; i++) {
        // Nested loop
        // Loop from 'n' to 1 to print the numbers in descending order
        for (int j = n; j >= 1; j--) { // Opposite Loop
            cout << j << " ";  // Print the current value of 'j' followed by a space
        }
        cout << endl;  // Move to the next line after printing all columns for the current row
    }

    return 0;  // Return 0 to indicate successful execution
}

/*
Output Example:
5 4 3 2 1 
5 4 3 2 1 
5 4 3 2 1 
5 4 3 2 1 
5 4 3 2 1  
*/
