#include <iostream> // Include the input-output stream library
using namespace std; // Use the standard namespace

int main() {
    // i=row, j=column
    int num;

    // Prompt the user to enter a number
    cout << "Enter a number :";
    // Read the entered number and store it in the variable 'num'
    cin >> num;

    // Outer loop to handle the number of rows
    for (int i = 1; i <= num; i++) {
        // Calculate the starting character for the current row
        char name = 'a' + (i - 1);
        // Nested loop to handle the number of columns
        for (int j = 1; j <= num; j++) {
            // Print the character followed by two spaces
            cout << name << "  ";
        }
        // Print a newline character after each row
        cout << endl;
    }

    return 0; // Return 0 to indicate successful execution
}

/* Output:
a  a  a  a  a        
b  b  b  b  b        
c  c  c  c  c        
d  d  d  d  d        
e  e  e  e  e  
*/
