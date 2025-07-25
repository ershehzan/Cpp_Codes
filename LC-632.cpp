#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

class Solution {
public:
    // Function to find the smallest range that includes at least one number from each of the k lists
    vector<int> smallestRange(vector<vector<int>>& nums) {
        // Min-heap to store elements in the form {value, {row, col}}
        // value: the element itself
        // row: which list the element comes from
        // col: the index within that list
        priority_queue< pair<int, pair<int, int>>, 
                        vector< pair<int, pair<int, int>>>, 
                        greater< pair<int, pair<int, int>>>> p;

        int minimum;                    // To track the current minimum value in the heap
        int maximum = INT_MIN;          // To track the current maximum value among selected elements

        // Initialize the heap by pushing the first element of each list
        for (int i = 0; i < nums.size(); i++) {
            p.push({nums[i][0], {i, 0}});             // Push the first element from nums[i]
            maximum = max(maximum, nums[i][0]);       // Update the maximum with the first element
        }

        minimum = p.top().first;                      // Initial minimum is the top element in the heap
        vector<int> ans = {minimum, maximum};         // Initial answer range

        // Continue while all lists have elements in the heap
        while (true) {
            auto temp = p.top();                      // Get the smallest element from the heap
            p.pop();                                  // Remove it from the heap

            int elem = temp.first;                    // Current minimum element value
            int row = temp.second.first;              // Row (list) the element came from
            int col = temp.second.second;             // Index within that list

            // Try to move forward in the same list, if possible
            if (col + 1 < nums[row].size()) {
                col++;                                // Move to next index in the current list
                p.push({nums[row][col], {row, col}}); // Push the next element from the same list
                maximum = max(maximum, nums[row][col]); // Update the maximum if necessary
                minimum = p.top().first;              // Minimum is always the smallest in the heap

                // Update answer if the current range is smaller than the previous best
                if (maximum - minimum < ans[1] - ans[0]) {
                    ans[0] = minimum;
                    ans[1] = maximum;
                }
            } else {
                // If any list is exhausted, we can no longer include all lists in the range, so break
                break;
            }
        }

        // Return the smallest range found
        return ans;
    }
};

int main() {
    Solution sol;

    // Example test input: three sorted lists
    vector<vector<int>> nums = {
        {4, 10, 15, 24, 26},
        {0, 9, 12, 20},
        {5, 18, 22, 30}
    };

    vector<int> result = sol.smallestRange(nums);

    // Print the result
    cout << "Smallest range is: [" << result[0] << ", " << result[1] << "]" << endl;

    return 0;
}
