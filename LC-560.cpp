// Include necessary headers
#include <iostream>        // For input/output operations
#include <vector>          // For using vector container
#include <unordered_map>   // For using hash map to store prefix sums

using namespace std;

// Main class containing the solution
class Solution {
public:
    // Function to count the number of subarrays that sum to k
    int subarraySum(vector<int>& nums, int k) {
        int total = 0;                  // Stores the total number of subarrays found
        int prefixSum = 0;              // Accumulates the sum of elements as we traverse the array
        unordered_map<int, int> m;      // Hash map to store prefix sums and their frequencies
        m[0] = 1;                       // Initialize map with 0 sum to handle subarrays starting at index 0

        // Iterate through the array
        for (int i = 0; i < nums.size(); i++) {
            prefixSum += nums[i];       // Update the prefix sum with the current element

            // Check if there is a prefix sum such that prefixSum - k exists in the map
            // If it exists, it means there is a subarray ending at index i with sum k
            if (m.count(prefixSum - k)) {
                total += m[prefixSum - k]; // Add the number of times (prefixSum - k) has occurred
            }

            // Update the frequency of the current prefixSum in the map
            m[prefixSum]++;
        }

        return total; // Return the final count of subarrays
    }
};

int main() {
    Solution sol;

    // Example input
    vector<int> nums = {1, 2, 3, -2, 5}; // The array to search for subarrays
    int k = 5;                           // The target sum for subarrays

    // Call the function and store the result
    int result = sol.subarraySum(nums, k);

    // Output the result
    cout << "Number of subarrays with sum " << k << " is: " << result << endl;

    return 0; // Indicate successful program termination
}
