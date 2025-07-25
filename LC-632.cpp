#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        // Min-heap: {value, {row, col}}
        priority_queue< pair<int, pair<int, int>>, 
                        vector< pair<int, pair<int, int>>>, 
                        greater< pair<int, pair<int, int>>>> p;

        int minimum, maximum = INT_MIN;

        // Initialize the heap with the first element of each list
        for (int i = 0; i < nums.size(); i++) {
            p.push({nums[i][0], {i, 0}});
            maximum = max(maximum, nums[i][0]);
        }

        minimum = p.top().first;
        vector<int> ans = {minimum, maximum};

        while (true) {
            auto temp = p.top();
            p.pop();

            int elem = temp.first;
            int row = temp.second.first;
            int col = temp.second.second;

            // Move to next element in the same row
            if (col + 1 < nums[row].size()) {
                col++;
                p.push({nums[row][col], {row, col}});
                maximum = max(maximum, nums[row][col]);
                minimum = p.top().first;

                if (maximum - minimum < ans[1] - ans[0]) {
                    ans[0] = minimum;
                    ans[1] = maximum;
                }
            } else {
                // If one of the lists is exhausted, break
                break;
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;

    // Example test input
    vector<vector<int>> nums = {
        {4, 10, 15, 24, 26},
        {0, 9, 12, 20},
        {5, 18, 22, 30}
    };

    vector<int> result = sol.smallestRange(nums);

    cout << "Smallest range is: [" << result[0] << ", " << result[1] << "]" << endl;

    return 0;
}
