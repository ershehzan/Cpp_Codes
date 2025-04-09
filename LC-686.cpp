#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Class to solve the problem of repeated string match using KMP (Knuth-Morris-Pratt) algorithm.
class Solution {
public:
    // Helper function to compute the LPS (Longest Prefix Suffix) array for KMP algorithm.
    // Parameters:
    // - lps: Reference to the vector storing the LPS array.
    // - s: The string for which the LPS array is computed.
    void lpsfind(vector<int> &lps, string s) {
        int pre = 0, suf = 1;

        // Iterate through the string to calculate the LPS values.
        while (suf < s.size()) {
            if (s[pre] == s[suf]) {
                lps[suf] = pre + 1; // Match found, update LPS.
                pre++;
                suf++;
            } else {
                if (pre == 0) {
                    lps[suf] = 0; // No match, set LPS to 0.
                    suf++;
                } else {
                    pre = lps[pre - 1]; // Update pre to previous LPS.
                }
            }
        }
    }

    // Function to perform KMP string matching.
    // Parameters:
    // - haystack: The string in which we are searching.
    // - needle: The string to search for.
    // Returns:
    // - 1 if the needle is found in the haystack, 0 otherwise.
    int kmp_match(string haystack, string needle) {
        if (needle.empty()) return 0; // Edge case: Empty needle.

        vector<int> lps(needle.size(), 0); // Initialize LPS array.
        lpsfind(lps, needle); // Compute LPS array for the needle.

        int first = 0, second = 0; // Indices for haystack and needle.

        // Perform the KMP matching algorithm.
        while (first < haystack.size() && second < needle.size()) {
            if (haystack[first] == needle[second]) {
                first++;
                second++;
            } else {
                if (second == 0)
                    first++; // Move forward in haystack.
                else
                    second = lps[second - 1]; // Use LPS to skip comparisons.
            }
        }

        // Check if the entire needle was matched.
        if (second == needle.size())
            return 1; // Match found.
        else
            return 0; // No match.
    }

    // Function to determine the minimum number of times string 'a' needs
    // to be repeated so that 'b' becomes a substring of the repeated string.
    // Parameters:
    // - a: The string to be repeated.
    // - b: The target string to find as a substring.
    // Returns:
    // - The minimum number of repetitions of 'a' to contain 'b', or -1 if not possible.
    int repeatedStringMatch(string a, string b) {
        if (a == b)
            return 1; // If both strings are equal, one repetition is enough.

        int repeat = 1; // Start with one repetition.
        string temp = a; // Temporary string to hold repeated 'a'.

        // Repeat 'a' until its length is at least as long as 'b'.
        while (temp.size() < b.size()) {
            temp += a;
            repeat++;
        }

        // Check if 'b' is a substring using KMP.
        if (kmp_match(temp, b) == 1)
            return repeat;

        // Check by adding one more repetition of 'a'.
        if (kmp_match(temp + a, b) == 1)
            return repeat + 1;

        return -1; // If 'b' cannot be found, return -1.
    }
};

int main() {
    Solution solution;
    string a, b;

    // Input strings 'a' and 'b' from the user.
    cout << "Enter string a: ";
    cin >> a;
    cout << "Enter string b: ";
    cin >> b;

    // Call the function to find the result.
    int result = solution.repeatedStringMatch(a, b);
    cout << "Result: " << result << endl;

    return 0; // End of program.
}
