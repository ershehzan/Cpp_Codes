#include <iostream> 
using namespace std; 

// Function to check if a number is prime
bool isPrime(int n)
{
    if (n < 2) // Numbers less than 2 are not prime
        return false;
    
    // Loop from 2 to the square root of n
    // A number n is not prime if it has a divisor other than 1 and itself
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0) // If n is divisible by i, it's not a prime number
        {
            return false;
        }
    }
    return true; // If no divisors found, return true (n is prime)
}

int main()
{
    int n; // Variable to store user input
    cout << "Enter a number: "; // Prompt user to enter a number
    cin >> n; // Read user input
    
    int sum = 0; // Variable to store sum of prime numbers up to n

    // Check if the given number is prime and print the result
    if (isPrime(n))
    {
        cout << "Number is prime" << endl;
    }
    else
    {
        cout << "Number is not prime" << endl;
    }
    
    // Loop through numbers from 2 to n to find and sum prime numbers
    for (int i = 2; i <= n; i++)
    {
        if (isPrime(i)) // Check if i is prime
        {
            sum += i; // Add prime number to sum
        }
    }
    
    // Print the sum of prime numbers up to n
    cout << "Sum of prime numbers up to " << n << " is: " << sum << endl;
    
    return 0; 
}
