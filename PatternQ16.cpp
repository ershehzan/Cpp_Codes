#include <iostream>
using namespace std;

int main()
{
    int i, j, n;
    
    // Taking input from the user
    cout << "Enter the number : ";
    cin >> n;
    
    // Outer loop to control the rows
    for (i = 1; i <= n; i++)
    {
        // Inner loop to print decreasing numbers in each row
        for (j = 1; j <= n - (i - 1); j++)
        {
            cout << i << " "; // Print the current row number
        }
        cout << endl; // Move to the next line after printing numbers for the current row
    }
    
    return 0;
}

/* Output Example:
Enter the number : 5
1 1 1 1 1 
2 2 2 2 
3 3 3 
4 4 
5 
*/
