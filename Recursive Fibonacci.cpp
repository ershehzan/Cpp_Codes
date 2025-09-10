// Include the iostream library for input and output operations
#include <iostream>
using namespace std;
// Function to calculate the nth Fibonacci number using recursion
// The function takes an integer input `n`
// If n <= 1, it returns n directly as the base case (0 or 1)
// Otherwise, it recursively computes the sum of the previous two Fibonacci numbers
int fab(int n)
{
    // Base case: if n is 0 or 1, return n
    if (n <= 1)
    {
        return n;
    }

    // Recursive case: return the sum of the (n-1)th and (n-2)th Fibonacci numbers
    return fab(n - 1) + fab(n - 2);
}

int main(){
    // Declare a variable to store the number of terms in the Fibonacci series
    int n;

    // Prompt the user to enter the number of terms
    cout << "Enter the number of terms: ";
    cin >> n;

    // Output the nth Fibonacci number by calling the fab function
    // Note: The current implementation only calculates the nth term,
    // not the entire Fibonacci series up to n terms
    cout << "Fibonacci Series: " << fab(n) << endl;
}


