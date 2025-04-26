#include <iostream>
#include <cmath> // Include cmath for mathematical functions like pow()
using namespace std;

int main() {
    int n; // Declare an integer variable to store the user's input
    
    // Prompt the user to input the value of n
    cout << "Enter the value of n: ";
    cin >> n; // Read the value of n from the user

    double sum = 0.0; // Initialize a variable to store the sum of the series

    // Loop through numbers from 1 to n to calculate the sum of the series
    for (int i = 1; i <= n; i++) {
        // Add the reciprocal of i raised to the power of i to the sum
        // pow(i, i) calculates i raised to the power of i
        // 1.0 ensures floating-point division
        sum += 1.0 / pow(i, i); 
    }

    // Print the final sum of the series
    cout << "Sum of the series: " << sum << endl;

    return 0; // Indicate that the program ended successfully
}
