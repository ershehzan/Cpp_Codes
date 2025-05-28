#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        stack<char> st;
        for (size_t i = 0; i < s.size(); i++) {
            st.push(s[i]);
        }
        int i = 0;
        while (!st.empty()) {
            s[i] = st.top();
            st.pop();
            i++;
        }
    }
};

int main() {
    Solution solution;
    int n;
    cout << "Enter the number of characters: ";
    cin >> n;
    vector<char> s(n);
    cout << "Enter the characters (no spaces): ";
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    solution.reverseString(s);

    cout << "Reversed string: ";
    for (char c : s) {
        cout << c;
    }
    cout << endl;



    return 0;
}