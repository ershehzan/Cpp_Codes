#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) return 0;

        int product = 1;
        int start = 0, end = 0;
        int n = nums.size();
        int count = 0;

        while (end < n) {
            product *= nums[end];

            while (product >= k && start <= end) {
                product /= nums[start];
                start++;
            }

            count += end - start + 1;
            end++;
        }
        return count;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {10, 5, 2, 6};
    int k = 100;

    int result = sol.numSubarrayProductLessThanK(nums, k);
    cout << "Number of subarrays with product less than " << k << ": " << result << endl;

    return 0;
}
