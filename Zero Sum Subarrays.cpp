#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int findSubarray(vector<int> &arr) {
        // Initialize total number of subarrays with sum = 0
        long long int total = 0;

        // Hash map to store frequency of prefix sums
        unordered_map<long long int, long long int> m;

        // Variable to maintain prefix sum
        long long int prefixSum = 0;

        // A prefix sum of 0 means a subarray from the start has sum = 0
        m[0] = 1;

        // Traverse the array
        for (int i = 0; i < arr.size(); i++) {
            // Update prefix sum
            prefixSum += arr[i];

            // If this prefix sum has been seen before,
            // it means subarrays between previous indices and current have sum = 0
            if (m.count(prefixSum)) {
                total += m[prefixSum];  // Add the number of such occurrences to total
                m[prefixSum]++;         // Increment the count for current prefixSum
            } else {
                m[prefixSum] = 1;       // First time seeing this prefixSum
            }
        }

        // Return total number of subarrays with sum = 0
        return total;
    }
};

int main() {
    Solution sol;

    // Example input
    vector<int> arr = {1, -1, 2, -2, 3};

    // Call the function
    int result = sol.findSubarray(arr);

    // Output the result
    cout << "Number of subarrays with sum = 0 is: " << result << endl;

    return 0;
}
