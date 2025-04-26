#include<iostream>
#include<cmath> // Include cmath for mathematical functions
using namespace std;
int main() {
    int n;
   

    cout << "Enter the value of n: ";
    cin >> n; // Prompt the user to input the value of n

    double sum = 0.0; // Initialize the variable to store the sum of the series

    // Loop through numbers from 1 to n to calculate the sum of the series
    for (int i = 1; i <= n; i++) {
        // Add the reciprocal of i raised to the power of i to the sum
        sum += 1.0 / pow(i, i); 
    }

    // Print the final sum of the series
   cout << "Sum of the series: " << sum << endl;
    

    return 0;
}