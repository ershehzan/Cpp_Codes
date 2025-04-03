#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    string sortSentence(string s)
    {
        vector<string> ans(10);
        string temp = "";
        int idx = 0;
        int count = 0;

        while (idx < s.size())
        {
            if (s[idx] == ' ')
            {
                int pos = temp[temp.size() - 1] - '0';
                temp.pop_back();
                ans[pos] = temp;
                temp.clear();
                count++;
            }
            else
            {
                temp += s[idx];
            }
            idx++;
        }

        int pos = temp[temp.size() - 1] - '0';
        temp.pop_back();
        ans[pos] = temp;
        temp.clear();
        count++;

        for (int i = 1; i <= count; i++)
        {
            temp += ans[i];
            temp += ' ';
        }
        temp.pop_back();

        return temp;
    }
};

int main()
{
    Solution solution;
    string input;
    cout << "Enter a shuffled sentence: ";
    getline(cin, input);

    string result = solution.sortSentence(input);
    cout << "The sorted sentence is: " << result << endl;

    return 0;
}


