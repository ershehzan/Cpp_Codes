#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Solution class encapsulates the logic for checking if the target array can be constructed
class Solution {
public:
    // Determines if it is possible to construct the target array from an array of ones
    bool isPossible(vector<int>& target) {
        // Max heap (priority queue) to always access the largest element efficiently
        priority_queue<long long> p;
        long long sum = 0; // Stores the sum of all elements in the target

        // Initialize the heap and compute the total sum
        for (int num : target) {
            p.push(num); // Push each target element into the max heap
            sum += num;  // Add to the running total
        }

        // Continue until the largest number is reduced to 1
        while (p.top() != 1) {
            long long maxEle = p.top(); p.pop(); // Extract the largest element
            long long restSum = sum - maxEle;    // Calculate the sum of the rest of the elements

            // If restSum is zero or maxEle is not greater than restSum, it's not possible
            if (restSum == 0 || maxEle <= restSum)
                return false;

            // Find what the previous value of maxEle would have been before the latest operation
            long long prev = maxEle % restSum;

            // If prev is zero, only valid if restSum is 1, otherwise not possible
            if (prev == 0) {
                return restSum == 1;
            }

            // Update the total sum and push the reduced element back into the heap
            sum = restSum + prev;
            p.push(prev);
        }

        // If all elements have been reduced to 1, return true
        return true;
    }
};

int main() {
    Solution sol;

    // Example test cases
    vector<int> target1 = {9, 3, 5};
    vector<int> target2 = {1, 1, 1, 2};
    vector<int> target3 = {8, 5};

    // Display the results of each test case
    cout << "Test Case 1: " << (sol.isPossible(target1) ? "true" : "false") << endl;
    cout << "Test Case 2: " << (sol.isPossible(target2) ? "true" : "false") << endl;
    cout << "Test Case 3: " << (sol.isPossible(target3) ? "true" : "false") << endl;

    return 0;
}
