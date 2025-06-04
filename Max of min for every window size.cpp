#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Solution class to solve the "Max of Min for Every Window Size" problem
class Solution {
  public:
    // Function to calculate the maximum of minimums for every window size
    vector<int> maxOfMins(vector<int>& arr) {
        int n = arr.size(); // Get the size of the array
        vector<int> ans(n, 0); // Result vector to store answers for all window sizes

        // Outer loop for window sizes from 1 to n
        for (int i = 0; i < n; i++) {
            // Inner loop to slide the window of size (i + 1) across the array
            for (int j = 0; j < n - i; j++) {
                int num = INT_MAX; // Initialize minimum to a large value
                // Find the minimum value in the current window
                for (int k = j; k < i + 1 + j; k++) {
                    num = min(num, arr[k]);
                }
                // Update the answer for this window size if current min is larger than previous
                ans[i] = max(ans[i], num);
            }
        }
        return ans; // Return the result vector
    }
};

int main() {
    Solution solution;
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    // Input array elements
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    // Get the result for all window sizes
    vector<int> result = solution.maxOfMins(arr);
    cout << "Max of min for every window size: ";
    // Output the result
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}
