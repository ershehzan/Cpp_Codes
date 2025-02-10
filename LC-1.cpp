#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map; // HashMap to store {value -> index}
        
        // Iterate through the array to find two numbers that add up to the target
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i]; // Calculate the required complement
            
            // Check if the complement exists in the map
            if (map.find(complement) != map.end()) {
                // If found, return the stored index of complement and current index
                return {map[complement], i};
            }

            // Store the current number and its index in the map
            map[nums[i]] = i;
        }
        
        // This line will never execute as per the problem constraints
        return {}; 
    }
};

int main() {
    Solution solution;
    vector<int> nums = {2, 7, 11, 15}; // Input array
    int target = 9; // Target sum

    // Call the twoSum function and store the result
    vector<int> result = solution.twoSum(nums, target);

    // Print the indices of the two numbers that sum up to the target
    cout << "[" << result[0] << ", " << result[1] << "]" << endl;
    
    return 0;
}
