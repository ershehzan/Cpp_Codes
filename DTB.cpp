#include <iostream>
using namespace std;

int main()
{
    int num;       // Variable to store the decimal number
    int rem;       // To store the remainder when dividing by 2
    int ans = 0;   // To store the binary equivalent
    int mul = 1;   // Multiplier to place the binary digit at the correct position

    // Input from the user
    cout << "Enter a Decimal Number : ";
    cin >> num;

    // Loop to convert decimal to binary
    while (num > 0)
    {
        rem = num % 2;  // Get remainder (0 or 1)
        num /= 2;       // Divide number by 2 for the next iteration
        ans += rem * mul; // Add remainder at the correct position
        mul *= 10;      // Update the position multiplier (units, tens, hundreds, etc.)
    }

    // Output the binary equivalent
    cout << "Binary Number is : " << ans;
    return 0;
}
