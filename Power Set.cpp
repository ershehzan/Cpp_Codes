#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Function to generate all subsequences (power set) of a given string
// s: Input string
// index: Current index in the input string
// n: Size of the input string
// ans: Vector to store all subsequences
// temp: Temporary string to build a subsequence during recursion
void subseq(string &s, int index, int n, vector<string>& ans, string temp)
{
    // Base case: If we have processed all characters of the string
    if (index == n)
    {
        ans.push_back(temp); // Add the generated subsequence to the result
        return;
    }

    // Recursive case 1: Exclude the current character and recurse
    subseq(s, index + 1, n, ans, temp);

    // Recursive case 2: Include the current character and recurse
    temp.push_back(s[index]); // Add the current character to the temporary string
    subseq(s, index + 1, n, ans, temp); // Recurse with the updated temporary string
}

int main()
{
    string s = "abc"; // Input string for which the power set is to be generated
    vector<string> ans; // Vector to store all subsequences
    string temp = ""; // Temporary string to build subsequences

    // Call the function to generate all subsequences starting from index 0
    subseq(s, 0, s.size(), ans, temp);

    // Print the generated power set
    cout << "The power set is: " << endl;
    for (size_t i = 0; i < ans.size(); i++)
        cout << "{" << ans[i] << "} "; // Print each subsequence enclosed in curly braces

    return 0; // Exit the program
}
