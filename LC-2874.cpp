#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long maxTripletValue(vector<int> &nums)
{
    int n = nums.size();

    // Prefix max array to keep track of maximum nums[i] for i < j
    vector<int> prefixMax(n, 0);
    prefixMax[0] = nums[0];
    for (int i = 1; i < n; i++)
    {
        prefixMax[i] = max(prefixMax[i - 1], nums[i]);
    }

    // Suffix max array to keep track of maximum nums[k] for k > j
    vector<int> suffixMax(n, 0);
    suffixMax[n - 1] = nums[n - 1];
    for (int k = n - 2; k >= 0; k--)
    {
        suffixMax[k] = max(suffixMax[k + 1], nums[k]);
    }

    long long maxValue = 0;

    // Iterate through j and find max value for triplet (i, j, k)
    for (int j = 1; j < n - 1; j++)
    {
        int leftMax = prefixMax[j - 1];  // Max nums[i] where i < j
        int rightMax = suffixMax[j + 1]; // Max nums[k] where k > j

        long long tripletValue = (1LL * (leftMax - nums[j])) * rightMax; // Ensure multiplication uses long long
        maxValue = max(maxValue, tripletValue);
    }

    return maxValue;
}

int main()
{
    vector<int> nums = {1000000, 1, 999999, 2, 1000000};
    cout << maxTripletValue(nums) << endl; // Expected output: large but valid
    return 0;
}
