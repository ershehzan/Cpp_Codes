#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        m[0] = 1;
        int prefixSum = 0;
        int total = 0;
        int rem;
        for (int i = 0; i < nums.size(); i++) {
            prefixSum += nums[i];
            rem = prefixSum % k;
            if (rem < 0)
                rem = k + rem;
            total += m[rem];
            m[rem]++;
        }
        return total;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {4, 5, 0, -2, -3, 1};
    int k = 5;

    int result = sol.subarraysDivByK(nums, k);
    cout << "Total subarrays divisible by " << k << ": " << result << endl;

    return 0;
}
