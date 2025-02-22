#include <iostream>
using namespace std;

int main()
{
    int num, ans = 0, rem, mul = 1;

    // Prompt the user to enter a number
    cout << "Enter a number: ";
    cin >> num;

    // Loop to process each bit of the number
    while (num)
    {
        // Get the remainder (last bit) when divided by 2 (binary representation)
        rem = num % 2;

        // Flip the bit using XOR operation (0 becomes 1, 1 becomes 0)
        rem = rem ^ 1;

        // Add the flipped bit to the result (ans) in its correct position
        ans += rem * mul;

        // Update multiplier for the next bit's position (i.e., move to the next power of 2)
        mul *= 2;

        // Remove the last bit by dividing the number by 2
        num /= 2;
    }

    // Output the result (bitwise complement of the original number)
    cout << ans;
    return 0;
}
