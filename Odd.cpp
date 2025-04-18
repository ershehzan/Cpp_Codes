#include <iostream>
using namespace std;

// A recursive function to print all odd numbers from 1 to n
void odd(int n)
{
    // Base case: If n is 1, print it and return
    if (n == 1)
    {
        cout << 1 << " ";
        return;
    }

    // Recursive call: Process numbers up to n-1
    odd(n - 1);

    // Check if the current number is odd
    if (n % 2 != 0)
    {
        // Print the current odd number
        cout << n << " ";
    }
}

int main()
{
    int n;

    // Prompt the user to enter a number
    cout << "Enter a number: ";
    cin >> n;

    // Inform the user about the output
    cout << "Odd numbers from 1 to " << n << ": ";

    // Call the recursive function to print odd numbers
    odd(n);

    // End the program
    return 0;
}
