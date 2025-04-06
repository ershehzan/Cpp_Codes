#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
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
    Solution solution;
    int num;

    cout << "Enter an integer: ";
    cin >> num;

    string roman = solution.intToRoman(num);
    cout << "Roman numeral: " << roman << endl;

    return 0;
}