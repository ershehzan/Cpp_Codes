#include <iostream>
using namespace std;

int main()
{
    int num;  // Variable to store user input
    cout << "Enter a number : ";
    cin >> num;  // Taking input from the user

    double fact = 1;  // Variable to store the factorial result, initialized to 1

    // Loop to calculate factorial
    for (int i = 1; i <= num; i++)
    {
        fact *= i;  // Multiply the current value of 'fact' by 'i' (fact = fact * i)
    }

    // Display the result
    cout << "Factorial of " << num << " is " << fact;

    return 0;  
}
