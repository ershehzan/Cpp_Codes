#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Class to solve the problem of sorting a shuffled sentence
class Solution
{
public:
    // Function to sort the shuffled sentence
    string sortSentence(string s)
    {
        // Vector to store the words at their correct positions
        vector<string> ans(10);
        string temp = "";  // Temporary string to store each word
        int idx = 0;       // Index to traverse the input string
        int count = 0;     // Count of words in the sentence

        // Loop through each character in the input string
        while (idx < s.size())
        {
            // If the character is a space, it indicates the end of a word
            if (s[idx] == ' ')
            {
                // Get the position of the word from the last character of temp
                int pos = temp[temp.size() - 1] - '0';
                temp.pop_back();   // Remove the position digit from temp
                ans[pos] = temp;   // Store the word at its correct position
                temp.clear();      // Clear temp for the next word
                count++;           // Increment the word count
            }
            else
            {
                // Append the character to temp
                temp += s[idx];
            }
            idx++;  // Move to the next character
        }

        // Process the last word (as it won't be followed by a space)
        int pos = temp[temp.size() - 1] - '0';
        temp.pop_back();   // Remove the position digit from temp
        ans[pos] = temp;   // Store the word at its correct position
        temp.clear();      // Clear temp
        count++;           // Increment the word count

        // Construct the sorted sentence
        for (int i = 1; i <= count; i++)
        {
            temp += ans[i];  // Append each word in the correct order
            temp += ' ';     // Add a space after each word
        }
        temp.pop_back();  // Remove the trailing space

        return temp;  // Return the sorted sentence
    }
};

int main()
{
    Solution solution;  // Create an instance of the Solution class
    string input;       // Variable to store the input sentence
    cout << "Enter a shuffled sentence: ";
    getline(cin, input);  // Read the input sentence from the user

    string result = solution.sortSentence(input);  // Sort the shuffled sentence
    cout << "The sorted sentence is: " << result << endl;  // Output the result

    return 0;
}
