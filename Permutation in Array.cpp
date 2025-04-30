#include <iostream>
#include <vector>
using namespace std;

// Solution class to generate all permutations of an array
class Solution {
public:
    // Recursive function to generate permutations
    // Parameters:
    // - arr: The input array to permute
    // - ans: A 2D vector to store all permutations
    // - index: The current index being processed
    void permute(vector<int>& arr, vector<vector<int>>& ans, int index) {
        // Base case: If the index reaches the size of the array, a permutation is complete
        if (arr.size() == index) {
            ans.push_back(arr); // Add the current permutation to the answer
            return;
        }

        // Iterate over the remaining elements to generate permutations
        for (int i = index; i < arr.size(); i++) {
            swap(arr[index], arr[i]); // Swap the current index with i to create a new permutation
            permute(arr, ans, index + 1); // Recursively generate permutations for the next index
            swap(arr[index], arr[i]); // Backtrack to restore the original array
        }
    }

    // Wrapper function to initiate the permutation process
    // Parameters:
    // - nums: Input array for which permutations are to be generated
    // Returns:
    // - A 2D vector containing all permutations of the input array
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans; // To store all permutations
        permute(nums, ans, 0); // Start recursion from the first index
        return ans; // Return the result
    }
};

int main() {
    Solution solution; // Create an instance of the Solution class
    vector<int> nums = {1, 2, 3}; // Example input array

    // Generate all permutations of the input array
    vector<vector<int>> result = solution.permute(nums);

    // Output the generated permutations
    cout << "Permutations of the array are:" << endl;
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " "; // Print each element of a permutation
        }
        cout << endl; // Move to the next line after printing each permutation
    }

    return 0; // Indicate successful program termination
}
