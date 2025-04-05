#include <iostream> // Include input-output stream library
#include <string>   // Include string library for string manipulation
using namespace std; // Use the standard namespace

// Class to convert Roman numeral to integer
class Solution {
public:
    // Function to return the integer value of a Roman numeral character
    int nums(char c) {
        if (c == 'I')
            return 1;
        else if (c == 'V')
            return 5;
        else if (c == 'X')
            return 10;
        else if (c == 'L')
            return 50;
        else if (c == 'C')
            return 100;
        else if (c == 'D')
            return 500;
        else
            return 1000; // For 'M'
    }

    // Function to convert a Roman numeral string to an integer
    int romanToInt(string s) {
        int sum = 0, index = 0;

        // Iterate through the string, except for the last character
        while (index < s.size() - 1) {
            // If current character is less than the next character, subtract its value
            if (nums(s[index]) < nums(s[index + 1]))
                sum -= nums(s[index]);
            else // Otherwise, add its value
                sum += nums(s[index]);

            index++; // Move to the next character
        }
        sum += nums(s[index]); // Add the value of the last character
        return sum; // Return the final sum
    }
};

int main() {
    Solution solution; // Create an instance of the Solution class
    string romanNumeral; // Declare a string to hold the Roman numeral

    cout << "Enter a Roman numeral: "; // Prompt the user for input
    cin >> romanNumeral; // Take input from the user

    int result = solution.romanToInt(romanNumeral); // Convert the Roman numeral to an integer
    cout << "The integer value is: " << result << endl; // Output the result

    return 0; // Return 0 to indicate successful execution
}
