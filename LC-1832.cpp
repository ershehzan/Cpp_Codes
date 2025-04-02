#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    bool checkIfPangram(string sentence)
    {
// start here
        vector<bool> alpha(26, 0);

        for (int i = 0; i < sentence.size(); i++)
        {
            alpha[sentence[i] - 'a'] = 1;
        }

        for (int i = 0; i < 26; i++)
        {
            if (alpha[i] == 0)
                return 0;
        }

        return 1;
        // end here
    }
};

int main()
{
    Solution solution;
    string sentence;

    cout << "Enter a sentence: ";
    getline(cin, sentence);

    if (solution.checkIfPangram(sentence))
    {
        cout << "The sentence is a pangram." << endl;
    }
    else
    {
        cout << "The sentence is not a pangram." << endl;
    }

    return 0;
}