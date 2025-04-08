// This program finds the longest prefix which is also a suffix in a given string.
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Class to provide solutions to specific problems
class Solution {
public:
    // Function to find the length of the longest prefix which is also a suffix
    // @param s: A reference to the input string
    // @return: The length of the longest prefix which is also a suffix
    int longestPrefixSuffix(string &s) {
        vector<int> lps(s.size(), 0);  // Vector to store the longest prefix suffix values
        int pre = 0, suf = 1;  // Pointers to track prefix and suffix positions

        // Iterate through the string to fill the lps array
        while (suf < s.size()) {
            // If characters match, increment both pointers and update lps array
            if (s[pre] == s[suf]) {
                lps[suf] = pre + 1;
                pre++;
                suf++;
            } else {
                // If characters do not match and pre is not at the start, update pre using lps array
                if (pre == 0) {
                    lps[suf] = 0;
                    suf++;
                } else {
                    pre = lps[pre - 1];
                }
            }
        }
        // Return the last value in lps array which represents the longest prefix which is also a suffix
        return lps[s.size() - 1];
    }
};

int main() {
    Solution solution;  // Create an instance of the Solution class
    string input;  // Variable to store the input string
    cout << "Enter a string: ";
    cin >> input;  // Read the input string from the user

    // Call the longestPrefixSuffix function and get the result
    int result = solution.longestPrefixSuffix(input);
    // Print the result
    cout << "The length of the longest prefix which is also a suffix is: " << result << endl;

    return 0;  
}
