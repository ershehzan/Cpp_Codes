#include <iostream> 
using namespace std; 

int main()
{
    int n, i, j; // Declare integer variables
    cout << "Enter the number : "; // Prompt the user to enter a number
    cin >> n; // Take input from the user and store it in variable n

    // Outer loop: Controls the number of rows in the pattern
    for (i = 1; i <= n; i++)
    {
        // Calculate the starting character for the current row
        // 'a' has ASCII value 97, so adding (i - 1) gives the correct character
        char name = 'a' + i - 1; 
        
        // Inner loop: Prints characters in the current row
        for (j = 1; j <= i; j++) 
        {
            cout << name << " "; // Print the character with a space
        }
        
        cout << endl; // Move to the next line after printing characters for a row
    }
    return 0; // Return 0 to indicate successful execution
}

/* Sample Output for n = 5
Enter the number : 5
a
b b
c c c
d d d d
e e e e e   
*/
