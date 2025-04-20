#include <iostream>
using namespace std;

// Recursive function to calculate the factorial of a number
// Parameter:
// - n: The number for which the factorial is to be calculated
int fact(int n)
{
    if (n == 0) // Base case: The factorial of 0 is 1
    {
        return 1;
    }
    return n * fact(n - 1); // Recursive call to calculate factorial
}

int main()
{
    int n; // Variable to store the user input
    cout << "Enter a number: "; // Prompt the user to enter a number
    cin >> n; // Read the input number from the user

    if (n < 0) // Check for negative numbers
    {
        cout << "Factorial of negative number doesn't exist" << endl; // Display error message
        return 0; // Exit the program
    }

    // Calculate and display the factorial of the entered number
    cout << "Factorial of " << n << " is: " << fact(n);
    return 0; // Return 0 to indicate successful program execution
}
