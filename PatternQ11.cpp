#include <iostream>
using namespace std;

int main(){
    
    int n, i, j; // Declare variables for user input and loop counters

    // Prompt the user to enter a number
    cout << "Enter the number : ";
    cin >> n; // Read user input

    // Outer loop controls the number of rows
    for (i = 1; i <= n; i++)
    {
        // Inner loop prints the current row number 'i' times
        for (j = 1; j <= i; j++)
        {
            cout << i << " "; // Print the current row number
        }
        cout << endl; // Move to the next line after printing each row
    }

    return 0; // Indicate successful program termination
}
/* Output Example (when user enters 5)
Enter the number: 5
1       
2 2     
3 3 3   
4 4 4 4 
5 5 5 5 5    
*/



