#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int findNumbers(vector<int> &nums)
    {
        int count = 0;
        for (size_t i = 0; i < nums.size(); i++)
        {
            int num = nums[i];
            int digits = 0;
            while (num > 0)
            {
                num /= 10;
                digits++;
            }
            if (digits % 2 == 0)
            {
                count++;
            }
        }
        return count;
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {12, 345, 2, 6, 7896};
    int result = solution.findNumbers(nums);
    cout << "The count of numbers with an even number of digits is: " << result << endl;
    return 0;
}