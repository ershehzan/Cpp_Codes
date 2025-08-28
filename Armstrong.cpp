#include <iostream>
#include <cmath> // For using pow() function
using namespace std;

// Function to count the number of digits in a given number
int countdigit(int n){
    int count = 0;
    while (n) // Loop runs until n becomes 0
    {
        count++;  
        n = n / 10; // Remove the last digit
    }
    return count; // Return the total count of digits
}

// Function to check whether a number is an Armstrong number
bool armstrong(int n, int digit){
    int temp = n, ans = 0, rem;
    
    // Loop to extract digits and compute the Armstrong sum
    while (temp)
    {
        rem = temp % 10; // Extract the last digit
        temp /= 10;      // Remove the last digit
        ans = ans + pow(rem, digit); // Add the digit raised to the power of 'digit'
    }

    return ans == n; // Return true if Armstrong condition is met, else false
}

int main(){
    int n;
    
    // User input
    cout << "Enter a number: ";
    cin >> n;

    // Count the number of digits in the input number
    int digit = countdigit(n);

    // Check if the number is an Armstrong number
    if (armstrong(n, digit))
        cout << n << " is an Armstrong number." << endl;
    else
        cout << n << " is not an Armstrong number." << endl;

    return 0; // Exit successfully
}



