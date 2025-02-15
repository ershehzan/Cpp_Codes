#include <iostream>
using namespace std; 

int main()
{
    int num, sum = 0; // Declare integer variables for user input and sum initialization
    cout << "Enter a Number :"; // Prompt the user to enter a number
    cin >> num; // Take input from the user and store it in variable num

    int i = 1; // Initialize loop variable i to 1
    
    // do-while loop ensures at least one iteration
    do
    {
        sum  += i; // Add the current value of i to sum
        cout << sum << endl; // Print the cumulative sum at each step
        i++; // Increment i

    } while (i <= num); // Continue looping until i exceeds num

    return 0; // Return 0 to indicate successful execution
}
