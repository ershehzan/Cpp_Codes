#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int celebrity(vector<vector<int>>& M) {
        int n = M.size();
        stack<int> st;

        // Step 1: Push all people into the stack
        for (int i = 0; i < n; i++) {
            st.push(i);
        }

        // Step 2: Eliminate non-celebrities
        while (st.size() > 1) {
            int a = st.top(); st.pop();
            int b = st.top(); st.pop();

            if (M[a][b] == 1) {
                // a knows b, so a cannot be a celebrity
                st.push(b);
            } else {
                // a doesn't know b, so b cannot be a celebrity
                st.push(a);
            }
        }

        // Step 3: Validate potential celebrity
        if (st.empty()) return -1;

        int candidate = st.top();
        st.pop();

        for (int i = 0; i < n; i++) {
            if (i != candidate) {
                // Candidate should not know i, and everyone should know candidate
                if (M[candidate][i] == 1 || M[i][candidate] == 0)
                    return -1;
            }
        }

        return candidate;
    }
};

int main() {
    Solution solution;
    int n;
    cout << "Enter the number of people: ";
    cin >> n;
    vector<vector<int>> M(n, vector<int>(n));
    cout << "Enter the matrix (row-wise, 0 or 1):" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> M[i][j];
        }
    }
    int result = solution.celebrity(M);
    if (result == -1)
        cout << "There is no celebrity." << endl;
    else
        cout << "Celebrity is person: " << result << endl;
    return 0;
}