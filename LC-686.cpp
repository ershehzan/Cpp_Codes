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

    int kmp_match(string haystack, string needle) {
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
            return 1;
        else
            return 0;
    }

    int repeatedStringMatch(string a, string b) {
        if (a == b)
            return 1;

        int repeat = 1;
        string temp = a;

        while (temp.size() < b.size()) {
            temp += a;
            repeat++;
        }

        // KMP
        if (kmp_match(temp, b) == 1)
            return repeat;

        // temp += a for KMP
        if (kmp_match(temp + a, b) == 1)
            return repeat + 1;

        return -1;
    }
};

int main() {
    Solution solution;
    string a, b;

    cout << "Enter string a: ";
    cin >> a;
    cout << "Enter string b: ";
    cin >> b;

    int result = solution.repeatedStringMatch(a, b);
    cout << "Result: " << result << endl;

    return 0;
}