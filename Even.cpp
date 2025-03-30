#include <iostream>
using namespace std;

int main()
{
    int n;  // Variable to store the user input
    cout << "Enter a number :";
    cin >> n;  // Taking input from the user

    int i = 1;  // Initialize loop counter

    // Loop to iterate from 1 to the entered number
    while (i <= n) // Loop will run until 'i' is less than or equal to 'num'
    {
        // Check if the current number is even
        if (i % 2 == 0)
        {
            cout << i << " ";  // Print even number
        }
        i++; // Increment the counter (Update step)
    }

    return 0; 
}
