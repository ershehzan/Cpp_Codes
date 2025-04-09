#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Class implementing the KMP (Knuth-Morris-Pratt) string matching algorithm.
class Solution {
public:
    // Helper function to compute the LPS (Longest Prefix Suffix) array for the KMP algorithm.
    // Parameters:
    // - lps: Reference to the vector storing the LPS array.
    // - s: The string for which the LPS array is computed.
    void lpsfind(vector<int> &lps, string s) {
        int pre = 0, suf = 1; // Initialize pointers for prefix and suffix.

        // Iterate over the string to calculate LPS values.
        while (suf < s.size()) {
            if (s[pre] == s[suf]) {
                lps[suf] = pre + 1; // Match found, update LPS.
                pre++;
                suf++;
            } else {
                if (pre == 0) {
                    lps[suf] = 0; // No prefix match, set LPS to 0.
                    suf++;
                } else {
                    pre = lps[pre - 1]; // Move prefix pointer using LPS array.
                }
            }
        }
    }

    // Function to find the index of the first occurrence of `needle` in `haystack` using KMP algorithm.
    // Parameters:
    // - haystack: The string in which to search.
    // - needle: The string to search for.
    // Returns:
    // - The index of the first occurrence of needle in haystack, or -1 if not found.
    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0; // Edge case: Empty needle.

        vector<int> lps(needle.size(), 0); // Initialize the LPS array.
        lpsfind(lps, needle); // Compute LPS array for the needle.

        int first = 0, second = 0; // Indices for haystack and needle.

        // Perform the KMP matching algorithm.
        while (first < haystack.size() && second < needle.size()) {
            if (haystack[first] == needle[second]) {
                first++;
                second++;
            } else {
                if (second == 0)
                    first++; // Move forward in haystack if no match.
                else
                    second = lps[second - 1]; // Use LPS to skip unnecessary comparisons.
            }
        }

        // Check if the entire needle was matched.
        if (second == needle.size())
            return first - second; // Return the starting index of the match.
        else
            return -1; // No match found.
    }
};

int main() {
    Solution solution;
    string haystack, needle;

    // Get the haystack string from the user.
    cout << "Enter the haystack string: ";
    cin >> haystack;

    // Get the needle string from the user.
    cout << "Enter the needle string: ";
    cin >> needle;

    // Call the function to get the result.
    int result = solution.strStr(haystack, needle);

    // Output the result.
    if (result != -1) {
        cout << "The needle is found at index: " << result << endl;
    } else {
        cout << "The needle is not found in the haystack." << endl;
    }

    return 0; // End of program.
}
