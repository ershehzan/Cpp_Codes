#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    string sortVowels(string s)
    {
        vector<int> lower(26, 0);
        vector<int> upper(26, 0);

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
            {
                lower[s[i] - 'a']++;
                s[i] = '#';
            }
            else if (s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
            {
                upper[s[i] - 'A']++;
                s[i] = '#';
            }
        }

        string vowel;

        // upper
        for (int i = 0; i < 26; i++)
        {
            char c = 'A' + i;
            while (upper[i])
            {
                vowel += c;
                upper[i]--;
            }
        }

        // lower
        for (int i = 0; i < 26; i++)
        {
            char c = 'a' + i;
            while (lower[i])
            {
                vowel += c;
                lower[i]--;
            }
        }

        int first = 0;
        size_t sec = 0;

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
    cout << "Enter a string: ";
    cin >> input;

    string result = solution.sortVowels(input);
    cout << "Result after sorting vowels: " << result << endl;

    return 0;
}