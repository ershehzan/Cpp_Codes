#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Class to encapsulate the solution
class Solution
{
public:
    // Function to sort vowels in a string
    string sortVowels(string s)
    {
        // Vectors to count occurrences of each lowercase and uppercase letter
        vector<int> lower(26, 0);
        vector<int> upper(26, 0);

        // Loop through each character in the string
        for (int i = 0; i < s.size(); i++)
        {
            // Check if the character is a lowercase vowel
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
            {
                // Increment the count for the corresponding vowel
                lower[s[i] - 'a']++;
                // Replace the vowel with a placeholder character
                s[i] = '#';
            }
            // Check if the character is an uppercase vowel
            else if (s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
            {
                // Increment the count for the corresponding vowel
                upper[s[i] - 'A']++;
                // Replace the vowel with a placeholder character
                s[i] = '#';
            }
        }

        // String to store sorted vowels
        string vowel;

        // Append uppercase vowels to the vowel string in sorted order
        for (int i = 0; i < 26; i++)
        {
            char c = 'A' + i;
            while (upper[i])
            {
                vowel += c;
                upper[i]--;
            }
        }

        // Append lowercase vowels to the vowel string in sorted order
        for (int i = 0; i < 26; i++)
        {
            char c = 'a' + i;
            while (lower[i])
            {
                vowel += c;
                lower[i]--;
            }
        }

        // Indices for iterating through the original string and the vowel string
        int first = 0;
        size_t sec = 0;

        // Replace placeholder characters in the original string with sorted vowels
        while (sec < vowel.size())
        {
            if (s[first] == '#')
            {
                s[first] = vowel[sec];
                sec++;
            }
            first++;
        }
        return s;
    }
};

int main()
{
    Solution solution;
    string input;

    // Prompt user for input
    cout << "Enter a string: ";
    cin >> input;

    // Sort vowels in the input string
    string result = solution.sortVowels(input);

    // Display the result
    cout << "Result after sorting vowels: " << result << endl;

    return 0;
}
