#include <iostream>
using namespace std;

int main()
{
    int n; // Variable to store the binary number input
    int rem, ans = 0, mul = 1; // rem: remainder, ans: decimal equivalent, mul: place value multiplier

    // Input: Get the binary number from the user
    cout << "Enter a Binary number: ";
    cin >> n;

    // Convert binary to decimal
    while (n > 0)
    {
        rem = n % 10; // Extract the last digit (remainder)
        n /= 10;      // Remove the last digit (quotient)
        ans += rem * mul; // Convert and add the value to the decimal result
        mul *= 2;       // Update the multiplier (power of 2)
    }

    // Output the decimal equivalent
    cout << "Decimal number is: " << ans;

    return 0;
}
