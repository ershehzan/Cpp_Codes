// Include the iostream library for handling input and output operations
#include <iostream>
using namespace std;
// Function to calculate the Greatest Common Divisor (GCD) of two integers using recursion
// Parameters:
// - `a`: First integer
// - `b`: Second integer
// If b equals 0, the GCD is a (base case).
// Otherwise, the function recursively calls itself with `b` and the remainder of `a % b`.
int GCD(int a, int b){
    // Base case: if the second number (b) is 0, return the first number (a) as the GCD
    if (b == 0)
    {
        return a;
    }

    // Recursive case: calculate GCD of `b` and the remainder of `a % b`
    return GCD(b, a % b);
}

int main(){
    // Declare two integer variables to store user input
    int a, b;
    
    // Prompt the user to enter two integers
    cout << "Enter the Two numbers: ";
    cin >> a >> b;

    // Output the GCD of the two numbers by calling the GCD function
    cout << "GCD of " << a << " and " << b << " is: " << GCD(a, b) << endl;
}



