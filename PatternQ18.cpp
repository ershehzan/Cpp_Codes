#include <iostream> 
using namespace std;

int main(){
    
    int n, i, j; // Declare variables
    cout << "Enter the number: ";
    cin >> n; // Take input from the user

    // Outer loop: Controls the number of rows (1 to n)
    for (i = 1; i <= n; i++)
    {
        // Inner loop 1: Prints spaces to align numbers to the right
        for (j = 1; j <= n - i; j++)
        {
            cout << " "; // Print space
        }

        // Inner loop 2: Prints decreasing numbers from 'i' to 1
        for (j = i; j >= 1; j--)
        {
            cout << j << " "; // Print number followed by a space
        }

        cout << endl; // Move to the next line after printing each row
    }

    return 0; 
}
/* Output

    1 
   2 1 
  3 2 1 
 4 3 2 1 
5 4 3 2 1 
   */



