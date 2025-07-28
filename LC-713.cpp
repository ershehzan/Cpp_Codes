#include <iostream>
#include <vector>
using namespace std;

// This class provides a solution to the problem of counting the number of contiguous subarrays
// where the product of all the elements in the subarray is less than a given value k.
class Solution {
public:
    // Function to count subarrays with product less than k
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        // If k is less than or equal to 1, no products can be less than k, so return 0
        if (k <= 1) return 0;

        int product = 1;      // Current product of window elements
        int start = 0, end = 0; // Window pointers
        int n = nums.size();  // Total number of elements in nums
        int count = 0;        // To store the result

        // Iterate through the array using the end pointer
        while (end < n) {
            // Multiply the current number to the product
            product *= nums[end];

            // If product is equal or greater than k, move start to the right
            // and divide out nums[start] from product until product < k
            while (product >= k && start <= end) {
                product /= nums[start];
                start++;
            }

            // All subarrays ending at 'end' and starting anywhere from 'start' to 'end' are valid
            count += end - start + 1;

            // Move end to the next element
            end++;
        }
        return count;
    }
};

int main() {
    Solution sol;

    // Example input array
    vector<int> nums = {10, 5, 2, 6};
    int k = 100;

    // Call the function and store result
    int result = sol.numSubarrayProductLessThanK(nums, k);

    // Output the result to the user
    cout << "Number of subarrays with product less than " << k << ": " << result << endl;

    return 0;
}
