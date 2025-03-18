#include <iostream>
using namespace std;

int main()
{
    // Declare an integer variable to store the number of rows and columns
    int num;

    // Prompt the user to enter a number and read the input value
    cout << "Enter a number: ";
    cin >> num;

    // Outer loop to handle the number of rows
    for (int i = 1; i <= num; i++)
    {
        // Inner loop to handle the number of columns
        for (int j = 1; j <= num; j++)
        {
            // Calculate the character to print based on the column index
            char name = 'a' + j - 1;
            // Print the character followed by two spaces
            cout << name << "  ";
        }
        // Print a newline character after each row
        cout << endl;
    }

    // Return 0 to indicate successful execution of the program
    return 0;
}

/* Output example when num = 5:
a  b  c  d  e        
a  b  c  d  e        
a  b  c  d  e        
a  b  c  d  e        
a  b  c  d  e   
*/
