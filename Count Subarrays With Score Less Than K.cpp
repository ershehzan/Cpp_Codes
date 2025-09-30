#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long ans = 0;
        long long sum = 0;
        int left = 0;
        
        for (int right = 0; right < nums.size(); ++right) {
            sum += nums[right];
            // Shrink from the left if the score is too big
            while (sum * (right - left + 1) >= k && left <= right) {
                sum -= nums[left];
                left++;
            }
            
            // All subarrays ending at 'right' and starting between [left, right] are valid
            ans += (right - left + 1);
        }
        
        return ans;
    }
};

int main(){
    
    Solution sol;
    vector<int> nums = {1, 2, 3, 4}; // Example input array
    long long k = 20; // Example threshold

    long long result = sol.countSubarrays(nums, k);
    cout << "Count of valid subarrays: " << result << endl;
    
    return 0;
}




