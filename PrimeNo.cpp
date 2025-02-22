#include <iostream>
using namespace std;

int main()
{
    int num;
    // Prompt user to enter a number
    cout << "Enter a number: ";
    cin >> num;

    // Check if the number is less than 2 (since 0 and 1 are not prime numbers)
    if (num < 2)
    {
        cout << "Number is not prime";
        return 0; // Exit the program
    }

    // Loop to check for factors from 2 to num/2
    for (int i = 2; i <= num / 2; i++) 
    {
        // If a divisor is found, the number is not prime
        if (num % i == 0)
        {
            cout << "Number is not prime";
            return 0; // Exit the program
        }
    }

    // If no divisors are found, the number is prime
    cout << "Number is prime";
    return 0; // Successful completion of the program
}
