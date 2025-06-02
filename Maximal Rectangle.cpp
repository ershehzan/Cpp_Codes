#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Class to encapsulate the solution for maximal rectangle problem
class Solution {
public:
    // Helper function to find the largest rectangle area in a histogram
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int index;
        int ans = 0;
        // Iterate through each bar in the histogram
        for (int i = 0; i < n; i++) {
            // While the current bar is lower than the bar at the stack's top
            while (!st.empty() && heights[st.top()] > heights[i]) {
                index = st.top();
                st.pop();
                // Calculate area considering the width between current and previous lower bar
                if (!st.empty())
                    ans = max(ans, heights[index] * (i - st.top() - 1));
                else
                    ans = max(ans, heights[index] * i); // If stack is empty, width is i
            }
            st.push(i); // Push current index to stack
        }
        // Process remaining bars in stack
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

    // Main function to find the maximal rectangle in a 2D binary matrix
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int ans = 0;
        int row = matrix.size();
        int col = matrix[0].size();
        vector<int> h(col, 0); // Histogram heights for each column
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (matrix[i][j] == '0')
                    h[j] = 0; // Reset height if cell is '0'
                else
                    h[j]++; // Increase height if cell is '1'
            }
            // Update maximal rectangle area for current row's histogram
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

    // Prepare the matrix and take user input
    vector<vector<char>> matrix(m, vector<char>(n));
    cout << "Enter the matrix (each row as a string of 0s and 1s):" << endl;
    for (int i = 0; i < m; i++) {
        string row;
        cin >> row;
        for (int j = 0; j < n; j++) {
            matrix[i][j] = row[j];
        }
    }

    // Compute and print the maximal rectangle area
    int result = solution.maximalRectangle(matrix);
    cout << "Maximal rectangle area: " << result << endl;
    return 0;
}
