#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        vector<bool> count(256, 0);
        int len = 0, first = 0, second = 0;

        while (second < s.size())
        {
            while (count[s[second]])
            {
                count[s[first]] = 0;
                first++;
            }

            count[s[second]] = 1;
            len = max(len, second - first + 1);
            second++;
        }
        return len;
    }
};

int main()
{
    Solution solution;
    string input;
    cout << "Enter a string: ";
    cin >> input;

    int result = solution.lengthOfLongestSubstring(input);
    cout << "Length of the longest substring without repeating characters: " << result << endl;

    return 0;
}