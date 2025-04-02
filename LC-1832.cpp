#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Class to solve the problem of checking if a sentence is a pangram
class Solution
{
public:
    // Function to check if the given sentence is a pangram
    bool checkIfPangram(string sentence)
    {
        // Vector to keep track of the occurrence of each alphabet letter
        vector<bool> alpha(26, 0);

        // Iterate through each character in the sentence
        for (int i = 0; i < sentence.size(); i++)
        {
            // Mark the corresponding position in the alpha vector
            alpha[sentence[i] - 'a'] = 1;
        }

        // Check if all alphabet letters are marked
        for (int i = 0; i < 26; i++)
        {
            if (alpha[i] == 0)
                return 0; // If any letter is not marked, return false
        }

        return 1; // If all letters are marked, return true
    }
};

int main()
{
    Solution solution;
    string sentence;

    // Prompt the user to enter a sentence
    cout << "Enter a sentence: ";
    getline(cin, sentence);

    // Check if the entered sentence is a pangram and display the result
    if (solution.checkIfPangram(sentence))
    {
        cout << "The sentence is a pangram." << endl;
    }
    else
    {
        cout << "The sentence is not a pangram." << endl;
    }

    return 0; // Return 0 to indicate successful execution
}
