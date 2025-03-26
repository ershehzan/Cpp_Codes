#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int can, count = 0, n = nums.size();

        // Step 1: Find a candidate using Boyer-Moore Voting Algorithm
        for (int i = 0; i < n; i++) {
            if (count == 0) {
                can = nums[i];
                count = 1;
            } else if (can == nums[i]) {
                count++;
            } else {
                count--;
            }
        }

        // Step 2: Verify if the candidate is the majority element
        count = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == can) {
                count++;
            }
        }

        return (count > n / 2) ? can : -1;  // Return -1 if no majority element exists
    }
};

// Driver Code
int main() {
    vector<int> nums = {3, 2, 3};
    Solution obj;
    cout << "Majority Element: " << obj.majorityElement(nums) << endl;

    return 0;
}
