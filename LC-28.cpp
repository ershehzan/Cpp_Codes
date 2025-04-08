#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    // Function to compute the Longest Prefix Suffix (LPS) array
    // for the given pattern string `s`
    void lpsfind(vector<int> &lps, string s) {
        int pre = 0, suf = 1;

        // Loop to fill the LPS array
        while (suf < s.size()) {
            if (s[pre] == s[suf]) {
                lps[suf] = pre + 1; // Extend the current prefix
                pre++;
                suf++;
            } else {
                if (pre == 0) {
                    lps[suf] = 0; // No common prefix found
                    suf++;
                } else {
                    pre = lps[pre - 1]; // Fall back to the previous longest prefix
                }
            }
        }
    }

    // Function to find the first occurrence of the substring `needle`
    // in the string `haystack` using the KMP algorithm
    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0; // Edge case: empty needle

        vector<int> lps(needle.size(), 0);
        lpsfind(lps, needle); // Compute the LPS array for the needle

        int first = 0, second = 0;

        // Loop to search for the needle in the haystack
        while (first < haystack.size() && second < needle.size()) {
            if (haystack[first] == needle[second]) {
                first++;
                second++;
            } else {
                if (second == 0)
                    first++;
                else
                    second = lps[second - 1]; // Fall back using the LPS array
            }
        }

        // Check if the entire needle was found in the haystack
        if (second == needle.size())
            return first - second;
        else
            return -1; // Needle not found
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
