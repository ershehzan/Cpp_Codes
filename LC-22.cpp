#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    void parenthesis(int n, int l, int r, vector<string>& ans, string& temp) {
        if (l + r == 2 * n) {
            ans.push_back(temp);
            return;
        }
        if (l < n) {
            temp.push_back('(');
            parenthesis(n, l + 1, r, ans, temp);
            temp.pop_back();
        }
        if (r < l) {
            temp.push_back(')');
            parenthesis(n, l, r + 1, ans, temp);
            temp.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string temp;
        parenthesis(n, 0, 0, ans, temp);
        return ans;
    }
};

int main() {
    Solution solution;
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    vector<string> result = solution.generateParenthesis(n);
    cout << "Generated Parentheses:" << endl;
    for (const string& s : result) {
        cout << s << endl;
    }

    return 0;
}