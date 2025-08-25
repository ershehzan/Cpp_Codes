#include <iostream>
#include <vector>
#include <string>
using namespace std;
// Solution class containing methods to generate valid parentheses combinations
class Solution {
public:
    // Recursive helper function to generate parentheses
    // n: Total number of pairs of parentheses
    // l: Current count of '(' used
    // r: Current count of ')' used
    // ans: Vector to store all valid combinations
    // temp: Current string being built
    void parenthesis(int n, int l, int r, vector<string>& ans, string& temp) 
       {
        // Base case: If the total length of the current string equals 2 * n,
        // it means a valid combination is formed
        if (l + r == 2 * n)
        {
            ans.push_back(temp); // Add the valid combination to the result
            return;
        }

        // If the number of '(' used is less than n, add '(' and recurse
        if (l < n) {
            temp.push_back('('); // Add '(' to the current string
            parenthesis(n, l + 1, r, ans, temp); // Recurse with incremented '(' count
            temp.pop_back(); // Backtrack by removing the last '('
        }

        // If the number of ')' used is less than the number of '(' used so far,
        // add ')' and recurse
        if (r < l) {
            temp.push_back(')'); // Add ')' to the current string
            parenthesis(n, l, r + 1, ans, temp); // Recurse with incremented ')' count
            temp.pop_back(); // Backtrack by removing the last ')'
        }
    }

    // Main function to generate all combinations of valid parentheses
    // n: Total number of pairs of parentheses
    vector<string> generateParenthesis(int n) 
    {
        vector<string> ans; // Vector to store the result
        string temp; // Temporary string to build combinations
        parenthesis(n, 0, 0, ans, temp); // Start the recursive generation
        return ans; // Return the result
    }
};

int main() {
    Solution solution; // Create an instance of the Solution class
    int n; // Variable to store the number of pairs of parentheses

    // Prompt the user to enter the value of n
    cout << "Enter the value of n: ";
    cin >> n;

    // Generate all valid parentheses combinations for the given n
    vector<string> result = solution.generateParenthesis(n);

    // Display the generated combinations
    cout << "Generated Parentheses:" << endl;
    for (const string& s : result) {
        cout << s << endl; // Print each combination
    }

    return 0; // Exit the program
}




