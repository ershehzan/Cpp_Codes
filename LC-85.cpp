#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Solution class encapsulates the logic for finding the maximal rectangle of 1's in a binary matrix
class Solution {
public:
    // Helper function to compute the largest rectangle in a histogram
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;        // Stack to store indices of histogram bars
        int index;
        int ans = 0;          // Variable to keep track of the maximum area found

        // Iterate through all bars of the histogram
        for (int i = 0; i < n; i++) {
            // If the current bar is lower than the bar at stack top, calculate area
            while (!st.empty() && heights[st.top()] > heights[i]) {
                index = st.top(); // Index of the bar to be popped
                st.pop();
                // If stack is not empty, calculate area using the width between current index and new top
                if (!st.empty())
                    ans = max(ans, heights[index] * (i - st.top() - 1));
                else
                    ans = max(ans, heights[index] * i); // If stack is empty, width is i
            }
            st.push(i); // Push current bar index to stack
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
        return ans; // Return the maximum rectangle area found
    }

    // Main function to compute maximal rectangle of 1's in a binary matrix
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;*

