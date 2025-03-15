#include <iostream>
using namespace std;

int main()
{
    // i = row, j = column
    int n, i, j;
    cout << "Enter the number of rows: ";
    cin >> n;

    for (i = 1; i <= n; i++)
    {
        // Print spaces for right alignment
        for (j = 1; j <= n - i; j++)
        {
            cout << "  "; // Two spaces for proper formatting
        }

        // Print numbers in increasing order
        for (j = 1; j <= i; j++)
        {
            cout << j << " ";
        }

        cout << endl; // Move to the next line after each row
    }

    return 0;
}

/* Output for n = 5

        1 
      1 2 
    1 2 3 
  1 2 3 4 
1 2 3 4 5 

*/
