#include <iostream> // Library for input and output operations
using namespace std;

// Recursive function to calculate the power of a number
// Parameters:
// - num: the base number
// - n: the exponent
// Returns:
// - num raised to the power of n
int pow(int num, int n)
{
    // Base case: any number raised to the power of 0 is 1
    if (n == 0)
    {
        return 1;
    }

    // Recursive case: multiply the base number with the result of num^(n-1)
    return num * pow(num, n - 1);
}

int main()
{
    int num; // Variable to store the base number

    // Prompt the user to enter the base number
    cout << "Enter the number: ";
    cin >> num;

    int n; // Variable to store the exponent

    // Prompt the user to enter the exponent
    cout << "Enter the power: ";
    cin >> n;

    // Handle the case where the exponent is negative
    if (n < 0)
    {
        cout << "Power of negative numbers is not supported in this program." << endl;
        return 0; // Exit the program
    }

    // Calculate and display the result
    cout << "Power of " << num << "^" << n << " is: " << pow(num, n) << endl;

    return 0; // Indicate successful program termination
}
