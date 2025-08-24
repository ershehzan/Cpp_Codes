// Circular string matching using KMP algorithm
#include<iostream>
#include<vector>
using namespace std;
// Helper function to compute the LPS (Longest Prefix Suffix) array for KMP algorithm.
// Parameters:
// - lps: Reference to the vector storing the LPS array.
// - txt: The string (pattern) for which the LPS array is computed.
void lpsfind(vector<int>& lps, string txt) 
{
    int prefix = 0, suffix = 1; // Initialize pointers for prefix and suffix.
    // Iterate over the string to calculate LPS values.
    while (suffix < txt.size()) {
        if (txt[prefix] == txt[suffix]) {
            lps[suffix] = prefix + 1; // Match found, update LPS.
            prefix++;
            suffix++;
        } else {
            if (prefix == 0) {
                lps[suffix] = 0; // No prefix match, set LPS to 0.
                suffix++;
            } else {
                prefix = lps[prefix - 1]; // Move prefix pointer using LPS array.
            }
        }
    }
}
int main() {
    // Input strings
    string txt = "cdeabroab"; // The main string
    string pattern = "abcde"; // The pattern to search for

    // Extend the main string by concatenating it with itself to handle circular matching.
    txt += txt;

    // Initialize the LPS array for the pattern.
    vector<int> lps(pattern.size(), 0);
    lpsfind(lps, pattern); // Compute the LPS array for the pattern.

    int first = 0, second = 0; // Indices for the main string and the pattern.

    // Perform the KMP matching algorithm.
    while (second < pattern.size() && first < txt.size()) {
        if (pattern[second] == txt[first]) {
            second++;
            first++;
        } else {
            if (second == 0) {
                first++; // Move forward in the main string if no match.
            } else {
                second = lps[second - 1]; // Use LPS to skip unnecessary comparisons.
            }
        }
    }

    // Check if the entire pattern was matched.
    if (second == pattern.size()) 
    {
        cout << "Matching"; // Pattern found in the circular string.
    } else 
    {
        cout << "Not Matching"; // Pattern not found.
    }

    return 0; // End of program.
}






