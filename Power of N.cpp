#include <iostream> // Including the header file for input/output operations
using namespace std;

// Recursive function to calculate the power of a number
// Parameters:
// - num: The base number
// - n: The exponent
int pow(int num, int n)
{
    if (n == 0) // Base case: Any number raised to the power of 0 is 1
    {
        return 1;
    }

    return num * pow(num, n - 1); // Recursive call to calculate power
};

int main()
{
    int num; // Variable to store the base number
    cout << "Enter the number: "; // Prompt the user to enter the base number
    cin >> num; // Read the base number from the user

    int n; // Variable to store the exponent
    cout << "Enter the power: "; // Prompt the user to enter the exponent
    cin >> n; // Read the exponent from the user

    if (n < 0) // Check for negative exponents
    {
        cout << "Power of negative number doesn't exist" << endl; // Display error message
        return 0; // Exit the program
    }

    // Calculate and display the power of the number
    cout << "Power of " << num << "^" << n << " is: " << pow(num, n) << endl;
    return 0; // Return 0 to indicate successful program execution
}
