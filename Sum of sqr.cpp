#include <iostream> // Including the header file for input/output operations
using namespace std;

// Recursive function to calculate the sum of squares of the first n natural numbers
// Parameter:
// - n: The number of natural numbers to include in the sum
int sumSqr(int n)
{
    if (n == 1) // Base case: The square of the first natural number is 1
    {
        return 1;
    }
    // Recursive case: Add the square of the current number to the sum of squares of previous numbers
    return n * n + sumSqr(n - 1);
};

int main()
{
    int n; // Variable to store the user input
    cout << "Enter a number: "; // Prompt the user to enter a number
    cin >> n; // Read the input number from the user

    if (n < 0) // Check for negative input
    {
        cout << "Please enter a non-negative integer." << endl; // Display error message for invalid input
        return 1; // Exit the program with an error code
    }

    // Calculate and display the sum of squares of the first n natural numbers
    cout << "Sum of squares of first " << n << " natural numbers is: " << sumSqr(n) << endl;

    return 0; // Return 0 to indicate successful program execution
}
