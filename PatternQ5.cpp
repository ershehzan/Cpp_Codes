#include <iostream> 
using namespace std; 
int main() {
    // i=row    j=column
    int n;  // Declare an integer variable 'n' to store the number of rows

    cout << "Enter a number :";  // Prompt the user to enter a number
    cin >> n;  // Read the input number and store it in 'n'

    // Loop from 1 to 'n' to iterate over each row
    for (int i = 1; i <= n; i++) {
        // Nested loop
        // Loop from 1 to 'n' to print '*' for each column in the current row
        for (int j = 1; j <= n; j++) {
            cout << " * ";  // Print '*' followed by a space
        }
        cout << endl;  // Move to the next line after printing all columns for the current row
    }

    return 0;  
}

/*
Output Example (for n=5):
 *  *  *  *  * 
 *  *  *  *  * 
 *  *  *  *  * 
 *  *  *  *  * 
 *  *  *  *  * 
*/
