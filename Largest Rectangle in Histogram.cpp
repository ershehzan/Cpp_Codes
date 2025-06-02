#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Solution class to find the largest rectangle in a histogram
class Solution {
public:
    // Function to compute the largest rectangle area in a histogram
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> right(n); // Stores the index of the next smaller element to the right
        vector<int> left(n);  // Stores the index of the next smaller element to the left
        stack<int> st;        // Monotonic stack to keep track of indices

        // Find the next smaller element to the right for each bar
        for (int i = 0; i < n; i++) {
            // While the stack is not empty and the current bar is smaller than the top of the stack
            while (!st.empty() && heights[st.top()] > heights[i]) {
                right[st.top()] = i; // The current index is the next smaller for the top of the stack
                st.pop();
            }
            st.push(i); // Push the current index onto the stack
        }
        // For remaining elements in the stack, there is no smaller element to the right
        while (!st.empty()) {
            right[st.top()] = n; // Assign 'n' (out of bounds)
            st.pop();
        }

        // Find the next smaller element to the left for each bar
        for (int i = n - 1; i >= 0; i--) {
            // While the stack is not empty and the current bar is smaller than the top of the stack
            while (!st.empty() && heights[st.top()] > heights[i]) {
                left[st.top()] = i; // The current index is the next smaller for the top of the stack
                st.pop();
            }
            st.push(i); // Push the current index onto the stack
        }
        // For remaining elements in the stack, there is no smaller element to the left
        while (!st.empty()) {
            left[st.top()] = -1; // Assign '-1' (out of bounds)
            st.pop();
        }

        int ans = 0; // To keep track of the maximum area found
        // Calculate the area for each bar as the smallest bar in its range
        for (int i = 0; i < n; i++) {
            // Area = height * width, width = right[i] - left[i] - 1
            ans = max(ans, heights[i] * (right[i] - left[i] - 1));
        }
        return ans;
    }
};

int main() {
    Solution solution;
    int n;
    cout << "Enter the number of bars in the histogram: ";
    cin >> n;
    vector<int> heights(n);
    cout << "Enter the heights of the bars: ";
    for (int i = 0; i < n; i++) {
        cin >> heights[i];
    }
    int result = solution.largestRectangleArea(heights);
    cout << "Largest rectangle area: " << result << endl;
    return 0;
}
