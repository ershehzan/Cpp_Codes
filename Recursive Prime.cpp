#include <iostream> // Including the header file for input/output operations
using namespace std;

// Function to recursively check if a number is prime
// Parameters:
// - n: The number to check for primality
// - i: The current divisor being checked (default is 2)
bool isPrimeRecursive(int n, int i = 2)
{
    if (n <= 1) // Base case: Numbers less than or equal to 1 are not prime
        return false;
    if (i == n) // Base case: If no divisors are found up to n, the number is prime
        return true;
    if (n % i == 0) // If n is divisible by i, it is not a prime number
        return false;

    // Recursive call with the next divisor
    return isPrimeRecursive(n, i + 1);
}

int main()
{
    int n; // Variable to store user input
    cout << "Enter a number: "; // Prompt the user to enter a number
    cin >> n; // Read the input number

    // Check if the number is prime and display the result
    if (isPrimeRecursive(n))
        cout << n << " is a prime number." << endl;
    else
        cout << n << " is not a prime number." << endl;

    return 0; // Return 0 to indicate successful program execution
}
