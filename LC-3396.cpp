#include <iostream>
#include <vector>
using namespace std;

// Class to provide solutions to specific problems
class Solution {
public:
    // Function to check if the array has any duplicate elements
    // @param nums: A vector of integers
    // @return: true if there are duplicates, false otherwise
    bool hasDuplicates(const vector<int>& nums) {
        // Iterate through each element in the vector
        for (int i = 0; i < nums.size(); ++i) {
            // Compare the current element with all subsequent elements
            for (int j = i + 1; j < nums.size(); ++j) {
                // If a duplicate is found, return true
                if (nums[i] == nums[j]) {
                    return true;
                }
            }
        }
        // If no duplicates are found, return false
        return false;
    }

    // Function to determine the minimum number of operations needed to remove all duplicates
    // @param nums: A vector of integers
    // @return: The number of operations required
    int minimumOperations(vector<int>& nums) {
        int operations = 0;  // Counter for the number of operations

        // Continue removing elements as long as there are duplicates
        while (hasDuplicates(nums)) {
            // If the size of the vector is less than or equal to 3, clear the entire vector
            if (nums.size() <= 3) {
                nums.clear();
            } else {
                // Otherwise, remove the first three elements from the vector
                nums.erase(nums.begin(), nums.begin() + 3);
            }
            operations++;  // Increment the operation count
        }

        // Return the total number of operations performed
        return operations;
    }
};

int main() {
    Solution solution;  // Create an instance of the Solution class
    vector<int> nums = {1, 2, 3, 1, 4, 5, 6, 2};  // Initialize a vector of integers with duplicates

    // Print the initial array
    cout << "Initial array: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    // Call the minimumOperations function to remove duplicates and get the result
    int result = solution.minimumOperations(nums);

    // Print the result of minimum operations
    cout << "Minimum operations to remove duplicates: " << result << endl;

    // Print the final state of the array after removing duplicates
    cout << "Final array: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;  
}
