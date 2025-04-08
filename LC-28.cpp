#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    void lpsfind(vector<int> &lps, string s) {
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
    }

    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;

        vector<int> lps(needle.size(), 0);
        lpsfind(lps, needle);

        int first = 0, second = 0;

        while (first < haystack.size() && second < needle.size()) {
            if (haystack[first] == needle[second]) {
                first++;
                second++;
            } else {
                if (second == 0)
                    first++;
                else
                    second = lps[second - 1];
            }
        }

        if (second == needle.size())
            return first - second;
        else
            return -1;
    }
};

int main() {
    Solution solution;
    string haystack, needle;

    cout << "Enter the haystack string: ";
    cin >> haystack;

    cout << "Enter the needle string: ";
    cin >> needle;

    int result = solution.strStr(haystack, needle);

    if (result != -1) {
        cout << "The needle is found at index: " << result << endl;
    } else {
        cout << "The needle is not found in the haystack." << endl;
    }

    return 0;
}