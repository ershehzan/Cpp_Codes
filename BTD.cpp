#include <iostream>
using namespace std;

int main()
{
    int num; // Variable to store the binary number input
    int rem, ans = 0, mul = 1; // rem: remainder, ans: decimal equivalent, mul: place value multiplier

    // Input: Get the binary number from the user
    cout << "Enter a Binary number: ";
    cin >> num;

    // Convert binary to decimal
    while (num > 0)
    {
        rem = num % 10; // Extract the last digit (remainder)
        num /= 10;      // Remove the last digit (quotient)
        ans += rem * mul; // Convert and add the value to the decimal result
        mul *= 2;       // Update the multiplier (power of 2)
    }

    // Output the decimal equivalent
    cout << "Decimal number is: " << ans;

    return 0;
}
