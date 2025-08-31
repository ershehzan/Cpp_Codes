// Sum from 1 to n using loop
#include <iostream>
using namespace std;
int main(){
    
    int n; // Variable to store the user input
    cout << "Enter a number : "; // Prompt the user to enter a number
    cin >> n; // Read the number input from the user
    int sum = 0; // Initialize a variable to store the sum, starting at 0
    // Loop from 1 to the input number (inclusive) to calculate the sum
    for (int i = 1; i <= n; i++)
    {
        sum += i; // Add the current value of `i` to the running total `sum`
    }
    // Display the final sum
    cout << "Sum from 1 to " << n << " is " << sum;
    return 0; // Indicate successful program termination
}








