#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Solution class to find the number of subarrays with sum zero
class Solution {
public:
    // Function to count the number of zero-sum subarrays
    int findSubarray(vector<int> &arr) {
        // Initialize total number of subarrays with sum = 0
        long long int total = 0;

        // Hash map to store frequency of prefix sums
        // Key: prefix sum value, Value: frequency/count of that prefix sum
        unordered_map<long long int, long long int> m;

        // Variable to maintain the running prefix sum as we iterate through the array
        long long int prefixSum = 0;

        // A prefix sum of 0 means a subarray from the start (index 0) has sum = 0.
        // We start by initializing its frequency to 1, so we can count such cases.
        m[0] = 1;

        // Traverse the array, calculating prefix sums and counting zero-sum subarrays
        for (int i = 0; i < arr.size(); i++) {
            // Update prefix sum by adding current element
            prefixSum += arr[i];

            // Check if this prefix sum has been seen before
            // If yes, it means there exists a subarray (between previous indices and current index)
            // whose sum is zero (because prefixSum - previousPrefixSum = 0)
            if (m.count(prefixSum)) {
                // Add the number of times this prefix sum has occurred so far to 'total'
                total += m[prefixSum];

                // Increment the frequency of the current prefix sum
                m[prefixSum]++;
            } else {
                // First time seeing this prefixSum, set its frequency to 1
                m[prefixSum] = 1;
            }
        }

        // Return the total number of subarrays with sum = 0 found in the array
        return total;
    }
};

int main() {
    Solution sol;

    // Example input array
    vector<int> arr = {1, -1, 2, -2, 3};

    // Call the function to find zero-sum subarrays
    int result = sol.findSubarray(arr);

    // Output the result
    cout << "Number of subarrays with sum = 0 is: " << result << endl;

    return 0;
}
