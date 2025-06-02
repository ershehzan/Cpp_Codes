#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Solution class to encapsulate the logic for finding the largest rectangle in a histogram
class Solution {
public:
    // Function to compute the largest rectangle area in a histogram
    int largestRectangleArea(vector<int>& heights) {
        
        int n = heights.size();   // Number of bars in the histogram
        
        stack<int> st;            // Stack to store indices of histogram bars
        int index;                // To store the index of the bar being processed
        int ans = 0;              // Variable to keep track of the maximum area found

        // Traverse all bars of the histogram
        for (int i = 0; i < n; i++) {
            // While the current bar is lower than the bar at top of the stack
            while (!st.empty() && heights[st.top()] > heights[i]) {
                index = st.top(); // Index of the bar to be popped
                st.pop();

                // If the stack is not empty, calculate area using the width between current index and new top
                if (!st.empty())
                    ans = max(ans, heights[index] * (i - st.top() - 1));
                else
                    ans = max(ans, heights[index] * i); // If stack is empty, width is i
            }
            st.push(i); // Push current bar index to stack
        }

        // Process remaining bars in the stack
        while (!st.empty()) {
            index = st.top();
            st.pop();

            if (!st.empty())
                ans = max(ans, heights[index] * (n - st.top() - 1));
            else
                ans = max(ans, heights[index] * n);
        }

        return ans; // Return the largest rectangle area found
    }
};

int main() {
    Solution solution;
    int n;
    cout << "Enter the number of bars in the histogram: ";
    cin >> n;
    vector<int> heights(n);

    // Input the heights of the histogram bars from the user
    cout << "Enter the heights of the bars: ";
    for (int i = 0; i < n; i++) {
        cin >> heights[i];
    }

    // Call the largestRectangleArea function and display the result
    int result = solution.largestRectangleArea(heights);
    cout << "Largest rectangle area: " << result << endl;
    return 0;
}
