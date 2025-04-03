#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Class to solve the problem of finding the longest palindrome that can be built with the letters of a given string
class Solution
{
public:
    // Function to calculate the length of the longest palindrome that can be built with the letters of the input string
    int longestPalindrome(string s)
    {
        // Vectors to count the frequency of each lowercase and uppercase letter in the input string
        vector<int> lower(26, 0);
        vector<int> upper(26, 0);

        // Loop through each character in the input string
        for (int i = 0; i < s.size(); i++)
        {
            // If the character is a lowercase letter, update the frequency in the lower vector
            if (s[i] >= 'a')
                lower[s[i] - 'a']++;
            // If the character is an uppercase letter, update the frequency in the upper vector
            else
                upper[s[i] - 'A']++;
        }

        int count = 0;  // Variable to store the length of the longest palindrome
        bool odd = 0;   // Flag to indicate if there is at least one character with an odd frequency

        // Loop through the frequency of each lowercase letter
        for (int i = 0; i < 26; i++)
        {
            // If the frequency is even, add it to the count
            if (lower[i] % 2 == 0)
            {
                count += lower[i];
            }
            else
            {
                // If the frequency is odd, add the largest even number less than the frequency to the count
                count += lower[i] - 1;
                odd = 1;  // Set the odd flag to true
            }
        }

        // Loop through the frequency of each uppercase letter
        for (int i = 0; i < 26; i++)
        {
            // If the frequency is even, add it to the count
            if (upper[i] % 2 == 0)
            {
                count += upper[i];
            }
            else
            {
                // If the frequency is odd, add the largest even number less than the frequency to the count
                count += upper[i] - 1;
                odd = 1;  // Set the odd flag to true
            }
        }

        // Return the length of the longest palindrome, adding 1 if there is at least one character with an odd frequency
        return count + odd;
    }
};

int main()
{
    Solution solution;  // Create an instance of the Solution class
    string input;       // Variable to store the input string
    cout << "Enter a string: ";
    cin >> input;       // Read the input string from the user

    int result = solution.longestPalindrome(input);  // Calculate the length of the longest palindrome
    cout << "The length of the longest palindrome that can be built is: " << result << endl;  // Output the result

    return 0;
}
