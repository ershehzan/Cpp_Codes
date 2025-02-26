#include <iostream>  
using namespace std;

int main()
{
    int num;  // Variable to store the input number

    // Prompt user for input
    cout << "Enter a number : ";
    cin >> num;

    // Loop until the number reduces to a single digit
    while (num > 9) 
    {
        int rem, ans = 0;  // Variables to store remainder and sum of digits
        
        while (num != 0) // Extract each digit and add it
        {
            rem = num % 10;  // Get the last digit
            num /= 10;        // Remove the last digit
            ans += rem;       // Add the digit to the sum
        }
        num = ans;  // Assign the computed sum to num for the next iteration
    }

    // Output the final single-digit sum
    cout << "Sum of digits until single digit is: " << num << endl;

    return 0;
}
