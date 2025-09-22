#include <iostream>
#include <vector>
using namespace std;

// Class to implement the Boyer-Moore Voting Algorithm
class Solution {
public:
    // Function to find the majority element in the given vector
    int majorityElement(vector<int>& nums) {
        int can, count = 0, n = nums.size();

        // Step 1: Find a candidate using Boyer-Moore Voting Algorithm
        // The idea is to maintain a count, which is incremented if the current element is the same as the candidate,
        // and decremented if different. If the count reaches zero, we choose the current element as the new candidate.
        for (int i = 0; i < n; i++)
       {
            if (count == 0) 
            {  // If count is zero, choose the current element as the candidate
                can = nums[i];
                count = 1;
            } else if (can == nums[i]) {  // If the current element is the same as the candidate, increment count
                count++;
            } else {  // If different, decrement count
                count--;
            }
        }

        // Step 2: Verify if the candidate is the majority element
        // We need to confirm that the candidate appears more than n/2 times in the array
        count = 0;  // Reset count
        for (int i = 0; i < n; i++)
            {
            if (nums[i] == can) {  // Count the occurrences of the candidate in the array
                count++;
            }
        }
        // Return the candidate if it is the majority element, otherwise return -1
        return (count > n / 2) ? can : -1;  // Return -1 if no majority element exists
    }
};
// Driver Code
int main() {
    vector<int> nums = {3, 2, 3};  // Input array
    Solution obj;  // Create an object of the Solution class
    cout << "Majority Element: " << obj.majorityElement(nums) << endl;  // Call the function and print the result

    return 0;
}





