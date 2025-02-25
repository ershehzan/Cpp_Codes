#include <iostream> 
using namespace std; 

int main()
{
    int n, rem, rev = 0; // Declare variables: n for input, rem for remainder, rev for reversed number
    cout << "Enter a number: "; // Prompt the user for input
    cin >> n; // Read the input number from the user

    // Loop until n becomes 0
    while (n != 0)
    {
        rem = n % 10; // Get the last digit of n
        rev = rev * 10 + rem; // Append the digit to the reversed number
        n /= 10; // Remove the last digit from n by dividing by 10
    }

    // Output the reversed number
    cout << "Reverse of the number is: " << rev;

    return 0;
}
