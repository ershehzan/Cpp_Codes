#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    // Function to find the majority element in the given array using Boyer-Moore Voting Algorithm
    int majorityElement(vector<int> &nums)
    {
        int can, count = 0, n = nums.size(); // 'can' stores the potential majority element, 'count' keeps track of its frequency

        // Iterate through the array to find the majority candidate
        for (int i = 0; i < n; i++)
        {
            if (count == 0) // If count becomes zero, choose a new candidate
            {
                count = 1;
                can = nums[i]; // Assign current number as the new candidate
            }
            else
            {
                if (can == nums[i]) // If the current number matches the candidate, increase the count
                {
                    count++;
                }
                else // Otherwise, decrease the count
                {
                    count--;
                }
            }
        }
        return can; // Return the candidate which is potentially the majority element
    }
};

int main()
{
    vector<int> nums = {3, 2, 3, 2, 3, 4, 5, 3, 2, 2, 2, 3}; // Example input array
    Solution sol; // Create an instance of the Solution class
    
    // Call the majorityElement function and print the result
    cout << "Majority Element: " << sol.majorityElement(nums) << endl;
    
    return 0; 
}
