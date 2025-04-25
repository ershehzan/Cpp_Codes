#include <iostream> // Library for input and output operations
using namespace std;

// Recursive function to print numbers from 1 to n
void print(int n)
{
    // Base case: when n equals 1, print 1 and stop recursion
    if (n == 1)
    {
        cout << n << endl; // Print the number 1
        return; // Exit the function
    }

    // Recursive call to print numbers from 1 to n-1
    print(n - 1);

    // Print the current number after the recursive call
    cout << n << endl;
}

int main()
{
    int n; // Variable to store the input number

    // Prompt the user to enter a number
    cout << "Enter a number: ";
    cin >> n; // Read the input from the user

    // Call the recursive print function to print numbers from 1 to n
    print(n);

    return 0; // Indicate successful program termination
}
