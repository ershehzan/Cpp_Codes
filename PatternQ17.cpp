#include <iostream> 
using namespace std;

int main()
{
    int n, i, j; // Declare variables

   
    cout << "Enter the number: ";
    cin >> n; // Take input from the user

    // Outer loop: Controls the number of rows (1 to n)
    for (i = 1; i <= n; i++)
    {
        // Inner loop: Prints decreasing numbers in each row
        // Starts from 'n' and decreases to 'n - i + 1'
        for (j = n; j >= n - i + 1; j--)
        {
            cout << j << " "; // Print the number followed by a space
        }

        cout << endl; // Move to the next line after printing each row
    }

    return 0; 
}

/* Output
5 
5 4 
5 4 3 
5 4 3 2 
5 4 3 2 1    */
