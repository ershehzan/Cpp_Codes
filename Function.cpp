#include <iostream>
using namespace std;
// Function to check if a number is prime
bool prime(int n){
    if (n <= 1)  // Numbers less than or equal to 1 are not prime
        return false;
    if (n == 2)  // 2 is a prime number
        return true;
    for (int i = 2; i <= n / 2; i++)  // Loop to check divisibility up to num/2
    {
        if (n % i == 0)  // If divisible, not a prime
            return false;
    }
    return true;  // If no divisors, it's prime
}

// Function to calculate factorial of a number
int fact(int n)
{
    int fact = 1;  // Initialize factorial as 1
    for (int i = 1; i <= n; i++)
    {
        fact *= i;  // Multiply the current number with the result
    }
    return fact;  // Return the computed factorial
}

int main(){
    int a, b;  // Variables to store user input

    // Input from the user
    cout << "Enter the first number: ";
    cin >> a;
    cout << "Enter the second number: ";
    cin >> b;

    // Check and display if 'a' is prime
    cout << "Is " << a << " a prime number? : " << (prime(a) ? "Yes" : "No") << endl;

    // Calculate and display factorial of 'b'
    cout << "Factorial of " << b << " is : " << fact(b) << endl;

    // Check and display if (b - a) is prime
    cout << "Is " << (b - a) << " a prime number? : " << (prime(b - a) ? "Yes" : "No") << endl;

    // Calculate and display factorial of (b - a)
    cout << "Factorial of " << (b - a) << " is : " << fact(b - a) << endl;

    return 0;  
}



