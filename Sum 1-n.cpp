#include <iostream>
using namespace std;

// A recursive function to calculate the sum of numbers from 1 to n
int print(int n)
{
    // Base case: If n is 0, return 0
    if (n == 0)
        return 0;

    // Recursive case: Add the current number to the sum of numbers from 1 to n-1
    return n + print(n - 1);
}

int main()
{
    int n;

    // Prompt the user to enter a number
    cout << "Enter a number: ";
    cin >> n;

    // Call the recursive function to compute the sum
    int result = print(n);

    // Display the result
    cout << "The sum of numbers from 1 to " << n << " is: " << result << endl;

    // End the program
    return 0;
}
