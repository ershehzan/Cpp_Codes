#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map; // HashMap to store {value -> index}
        
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i]; // Calculate the required complement
            
            // If complement is already in the map, return indices
            if (map.find(complement) != map.end()) {
                return {map[complement], i}; // Return stored index & current index
            }

            // Store current number and its index in the map
            map[nums[i]] = i;
        }
        
        return {}; // This line will never execute as per the problem constraints
    }
};

int main() {
    Solution solution;
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    vector<int> result = solution.twoSum(nums, target);

    cout << "[" << result[0] << ", " << result[1] << "]" << endl;
    
    return 0;
}
