#include <iostream> 
using namespace std;

int main()
{
    int n, i, j; // Declare variables

    // Prompt the user to enter a number
    cout << "Enter the number: ";
    cin >> n; // Take input from the user

    // Outer loop: Controls the number of rows (1 to n)
    for (i = 1; i <= n; i++)
    {
        // First inner loop: Prints spaces for right alignment
        for (j = 1; j <= n - i; j++)
        {
            cout << "  "; // Print two spaces
        }

        // Second inner loop: Prints numbers in decreasing order from 'i' to 1
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
