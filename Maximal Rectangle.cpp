#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int index;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] > heights[i]) {
                index = st.top();
                st.pop();
                if (!st.empty())
                    ans = max(ans, heights[index] * (i - st.top() - 1));
                else
                    ans = max(ans, heights[index] * i);
            }
            st.push(i);
        }
        while (!st.empty()) {
            index = st.top();
            st.pop();
            if (!st.empty())
                ans = max(ans, heights[index] * (n - st.top() - 1));
            else
                ans = max(ans, heights[index] * n);
        }
        return ans;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int ans = 0;
        int row = matrix.size();
        int col = matrix[0].size();
        vector<int> h(col, 0);
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (matrix[i][j] == '0')
                    h[j] = 0;
                else
                    h[j]++;
            }
            ans = max(ans, largestRectangleArea(h));
        }
        return ans;
    }
};

int main() {
    Solution solution;
    int m, n;
    cout << "Enter number of rows: ";
    cin >> m;
    cout << "Enter number of columns: ";
    cin >> n;
    vector<vector<char>> matrix(m, vector<char>(n));
    cout << "Enter the matrix (each row as a string of 0s and 1s):" << endl;
    for (int i = 0; i < m; i++) {
        string row;
        cin >> row;
        for (int j = 0; j < n; j++) {
            matrix[i][j] = row[j];
        }
    }
    int result = solution.maximalRectangle(matrix);
    cout << "Maximal rectangle area: " << result << endl;
    return 0;
}