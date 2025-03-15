#include <iostream>
using namespace std;

int main()
{
    // i = row index, j = column index
    int n, i, j;
    cout << "Enter the number of rows: ";
    cin >> n;

    for (i = 1; i <= n; i++) // Loop for each row
    {
        // Print leading spaces for right alignment
        for (j = 1; j <= n - i; j++)
        {
            cout << "  "; // Two spaces to maintain formatting
        }

        // Print numbers from 1 to i (ascending)
        for (j = 1; j <= i; j++)
        {
            cout << j << " ";
        }

        // Print numbers from (i-1) to 1 (descending)
        for (j = i - 1; j >= 1; j--)
        {
            cout << j << " ";
        }

        cout << endl; // Move to the next line after each row
    }

    return 0;
}
/* Output

        1 
      1 2 1 
    1 2 3 2 1        
  1 2 3 4 3 2 1      
1 2 3 4 5 4 3 2 1 

   */
