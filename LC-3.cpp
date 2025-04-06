#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Define a class named Solution
class Solution
{
public:
    // Function to find the length of the longest substring without repeating characters
    int lengthOfLongestSubstring(string s)
    {
        // Create a vector to keep track of characters in the current window
        vector<bool> count(256, 0);
        // Initialize variables for the length of the longest substring,
        // and pointers for the start and end of the current window
        int len = 0, first = 0, second = 0;

        // Iterate through the string using the 'second' pointer
        while (second < s.size())
        {
            // If the character at 'second' pointer is already in the window,
            // move the 'first' pointer to the right to remove characters until
            // the repeating character is removed
            while (count[s[second]])
            {
                count[s[first]] = 0;
                first++;
            }

            // Add the character at 'second' pointer to the window
            count[s[second]] = 1;
            // Update the length of the longest substring found so far
            len = max(len, second - first + 1);
            // Move the 'second' pointer to the right to expand the window
            second++;
        }
        // Return the length of the longest substring without repeating characters
        return len;
    }
};

int main()
{
    // Create an instance of the Solution class
    Solution solution;
    // Declare a string variable to store the input
    string input;
    // Prompt the user to enter a string
    cout << "Enter a string: ";
    // Read the input string from the user
    cin >> input;

    // Call the lengthOfLongestSubstring function and store the result
    int result = solution.lengthOfLongestSubstring(input);
    // Output the length of the longest substring without repeating characters
    cout << "Length of the longest substring without repeating characters: " << result << endl;

    return 0;
}
