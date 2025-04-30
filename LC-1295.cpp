#include <iostream>
#include <vector>
using namespace std;

// Class to provide solutions for problems
class Solution
{
public:
    // Function to find the count of numbers with an even number of digits
    int findNumbers(vector<int> &nums)
    {
        int count = 0; // Initialize counter for numbers with even digits
        
        // Iterate through each number in the input vector
        for (size_t i = 0; i < nums.size(); i++)
        {
            int num = nums[i]; // Get the current number
            int digits = 0;    // Counter for the number of digits
            
            // Calculate the number of digits in the current number
            while (num > 0)
            {
                num /= 10;  // Remove the last digit
                digits++;   // Increment digit count
            }

            // Check if the number of digits is even
            if (digits % 2 == 0)
            {
                count++; // Increment counter for numbers with even digits
            }
        }
        return count; // Return the total count
    }
};

int main()
{
    Solution solution; // Create an instance of the Solution class

    // Input vector containing the numbers to process
    vector<int> nums = {12, 345, 2, 6, 7896};

    // Call the function to get the result
    int result = solution.findNumbers(nums);

    // Output the result
    cout << "The count of numbers with an even number of digits is: " << result << endl;

    return 0; // Indicate that the program ended successfully
}
