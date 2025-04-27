#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int count = 0;
        int n = nums.size();
        
        for (int i = 0; i <= n - 3; ++i) {
            int first = nums[i];
            int second = nums[i + 1];
            int third = nums[i + 2];
            
            // Correct condition
            if (second % 2 == 0 && first + third == second / 2) {
                count++;
            }
        }
        
        return count;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {2, 4, 2, 6, 8, 4}; // Example input
    int result = solution.countSubarrays(nums);
    cout << "Count of valid subarrays: " << result << endl;
    return 0;
}