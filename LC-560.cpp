#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int total = 0;
        int prefixSum = 0;
        unordered_map<int, int> m;
        m[0] = 1;

        for (int i = 0; i < nums.size(); i++) {
            prefixSum += nums[i];

            if (m.count(prefixSum - k)) {
                total += m[prefixSum - k];
            }

            m[prefixSum]++;
        }

        return total;
    }
};

int main() {
    Solution sol;
    
    // Example input
    vector<int> nums = {1, 2, 3, -2, 5};
    int k = 5;

    // Call the function
    int result = sol.subarraySum(nums, k);

    // Output the result
    cout << "Number of subarrays with sum " << k << " is: " << result << endl;

    return 0;
}
