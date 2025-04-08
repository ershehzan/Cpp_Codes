// This program finds the longest prefix which is also a suffix in a given string.
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int longestPrefixSuffix(string &s) {
        vector<int> lps(s.size(), 0);
        int pre = 0, suf = 1;

        while (suf < s.size()) {
            if (s[pre] == s[suf]) {
                lps[suf] = pre + 1;
                pre++;
                suf++;
            } else {
                if (pre == 0) {
                    lps[suf] = 0;
                    suf++;
                } else {
                    pre = lps[pre - 1];
                }
            }
        }
        return lps[s.size() - 1];
    }
};

int main() {
    Solution solution;
    string input;
    cout << "Enter a string: ";
    cin >> input;

    int result = solution.longestPrefixSuffix(input);
    cout << "The length of the longest prefix which is also a suffix is: " << result << endl;

    return 0;
}