#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Define a class named Solution
class Solution
{
public:
    // Function to convert an integer to a Roman numeral
    string intToRoman(int num)
    {
        // Define the values of Roman numerals in descending order
        vector<int> values = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        // Define the corresponding Roman numeral symbols for the values
        vector<string> symbols = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

        // Initialize an empty string to store the resulting Roman numeral
        string result = "";

        // Iterate through each value-symbol pair
        for (size_t i = 0; i < values.size(); i++)
        {
            // While the current value can be subtracted from the number
            while (num >= values[i])
            {
                // Append the corresponding Roman numeral symbol to the result
                result += symbols[i];
                // Subtract the value from the number
                num -= values[i];
            }
        }

        // Return the final Roman numeral representation
        return result;
    }
};

int main()
{
    // Create an instance of the Solution class
    Solution solution;
    // Declare an integer variable to store the input number
    int num;

    // Prompt the user to enter an integer
    cout << "Enter an integer: ";
    // Read the input number from the user
    cin >> num;

    // Call the intToRoman function and store the result
    string roman = solution.intToRoman(num);
    // Output the Roman numeral representation of the input number
    cout << "Roman numeral: " << roman << endl;

    
    return 0;
}
