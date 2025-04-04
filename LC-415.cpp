#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// Class to encapsulate the solution
class Solution
{
public:
    // Function to add two numeric strings
    string add(string num1, string num2)
    {
        string ans;  // Resultant string to store the sum
        int index1 = num1.size() - 1, index2 = num2.size() - 1;  // Indices for iterating through the strings from the end
        int sum, carry = 0;  // Variables to store the sum and carry

        // Loop through both strings until the end of the shorter string
        while (index2 >= 0)
        {
            // Calculate the sum of the current digits and the carry
            sum = (num1[index1] - '0') + (num2[index2] - '0') + carry;
            carry = sum / 10;  // Calculate the new carry
            char c = '0' + sum % 10;  // Calculate the current digit
            ans += c;  // Append the current digit to the result
            index1--, index2--;  // Move to the next digits
        }
        
        // Continue adding the remaining digits of the longer string
        while (index1 >= 0)
        {
            sum = (num1[index1] - '0') + carry;  // Calculate the sum of the current digit and the carry
            carry = sum / 10;  // Calculate the new carry
            char c = '0' + sum % 10;  // Calculate the current digit
            ans += c;  // Append the current digit to the result
            index1--;  // Move to the next digit
        }
        
        // If there is a remaining carry, append it to the result
        if (carry)
            ans += '1';
        
        // Reverse the result string to get the correct order
        reverse(ans.begin(), ans.end());
        return ans;  // Return the resultant sum
    }

    // Function to add two numeric strings by ensuring the first string is the longer one
    string addStrings(string num1, string num2)
    {
        // If num1 is shorter than num2, swap them
        if (num1.size() < num2.size())
            return add(num2, num1);
        else
            return add(num1, num2);
    }
};

int main()
{
    Solution solution;
    string num1, num2;

    // Prompt user for the first number
    cout << "Enter the first number: ";
    cin >> num1;

    // Prompt user for the second number
    cout << "Enter the second number: ";
    cin >> num2;

    // Add the two numbers and display the result
    string result = solution.addStrings(num1, num2);
    cout << "The sum of the two numbers is: " << result << endl;

    return 0;
}
