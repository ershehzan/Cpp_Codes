#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int can, count = 0, n = nums.size();

        for (int i = 0; i < n; i++)
        {
            if (count == 0)
            {
                count = 1;
                can = nums[i];
            }
            else
            {
                if (can == nums[i])
                {
                    count++;
                }
                else
                {
                    count--;
                }
            }
        }
        return can;
    }
};

int main()
{
    vector<int> nums = {3, 2, 3,2,3,4,5,3,2,2,2,3};
    Solution sol;
    cout << "Majority Element: " << sol.majorityElement(nums) << endl;
    return 0;
}