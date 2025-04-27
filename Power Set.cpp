#include <iostream>
#include <vector>
#include <string>
using namespace std;

void subseq(string &s, int index, int n, vector<string>& ans, string temp)
{
    if (index == n)
    {
        ans.push_back(temp);
        return;
    }

    // Exclude the current character
    subseq(s, index + 1, n, ans, temp);

    // Include the current character
    temp.push_back(s[index]);
    subseq(s, index + 1, n, ans, temp);
}

int main()
{
    string s = "abc";
    vector<string> ans;
    string temp = "";

    subseq(s, 0, s.size(), ans, temp);

    cout << "The power set is: " << endl;
    for (size_t i = 0; i < ans.size(); i++)
        cout << "{" << ans[i] << "} ";

    return 0;
}
