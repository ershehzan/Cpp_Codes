#include <iostream>
using namespace std;

int main()
{
    int num;  // Variable to store the user input
    cout << "Enter a number :";
    cin >> num;  // Taking input from the user

    int i = 1;  // Initialize loop counter

    // Loop to iterate from 1 to the entered number
    while (i <= num) // Loop will run until 'i' is less than or equal to 'num'
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
