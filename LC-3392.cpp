#include <iostream>
#include <vector>
using namespace std;

// Solution class containing the method to count valid subarrays based on a specific condition
class Solution {
public:
    // Function to count subarrays of size 3 that satisfy a specific condition
    // nums: Input vector of integers
    int countSubarrays(vector<int>& nums) {
        int count = 0; // Counter to store the number of valid subarrays
        int n = nums.size(); // Size of the input vector

        // Iterate through the vector, stopping at the third-last element
        for (int i = 0; i <= n - 3; ++i) {
            int first = nums[i];       // First element of the current subarray
            int second = nums[i + 1]; // Second (middle) element of the current subarray
            int third = nums[i + 2];  // Third element of the current subarray
            
            // Check the condition:
            // 1. The middle element (second) must be even.
            // 2. The sum of the first and third elements must equal half of the middle element.
            if (second % 2 == 0 && first + third == second / 2) {
                count++; // Increment the counter if the condition is satisfied
            }
        }

        return count; // Return the total count of valid subarrays
    }
};

int main() {
    Solution solution; // Create an instance of the Solution class

    // Example input vector
    vector<int> nums = {2, 4, 2, 6, 8, 4};

    // Call the function to count valid subarrays and store the result
    int result = solution.countSubarrays(nums);

    // Output the result
    cout << "Count of valid subarrays: " << result << endl;

    return 0; // Exit the program
}
