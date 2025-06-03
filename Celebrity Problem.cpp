#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Solution class encapsulates the celebrity-finding logic
class Solution {
public:
    // Function to find the celebrity in the party matrix M
    int celebrity(vector<vector<int>>& M) {
        int n = M.size();
        stack<int> st; // Stack to keep track of potential celebrity candidates

        // Step 1: Push all people (0 to n-1) into the stack
        for (int i = 0; i < n; i++) {
            st.push(i);
        }

        // Step 2: Eliminate non-celebrities
        // Repeatedly pop two people off the stack and compare:
        // If person 'a' knows 'b', 'a' cannot be a celebrity
        // If person 'a' does not know 'b', 'b' cannot be a celebrity
        while (st.size() > 1) {
            int a = st.top(); st.pop();
            int b = st.top(); st.pop();

            if (M[a][b] == 1) {
                // a knows b, so a cannot be celebrity; keep b
                st.push(b);
            } else {
                // a does not know b, so b cannot be celebrity; keep a
                st.push(a);
            }
        }

        // Step 3: Validate the remaining candidate (if any)
        if (st.empty()) return -1; // No candidate found

        int candidate = st.top();
        st.pop();

        // Check if the candidate is a real celebrity:
        // 1. Candidate should not know anyone else.
        // 2. Everyone else should know the candidate.
        for (int i = 0; i < n; i++) {
            if (i != candidate) {
                // If candidate knows someone, or someone doesn't know candidate, not a celebrity
                if (M[candidate][i] == 1 || M[i][candidate] == 0)
                    return -1;
            }
        }

        // Candidate is a real celebrity
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
    // Input the relationship matrix
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
