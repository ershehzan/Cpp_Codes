#include <iostream> 
using namespace std; 

int main(){
    
    int n, sum = 0; // Declare variables: n for input, sum to store the sum of odd numbers

    // Prompt the user to enter the number of terms
    cout << "Enter the number of terms: ";
    cin >> n; // Read input value from the user

    // Loop from 1 to n to find the sum of the first n odd numbers
    for (int i = 1; i <= n * 2; i++) // Loop runs until it covers at least n odd numbers
    {
        if (i % 2 != 0) // Check if the number is odd
        {
            sum += i; // Add the odd number to the sum
        }
    }

    // Output the result
    cout << "The sum of the first " << n << " odd numbers is: " << sum;

    return 0; 
}


