#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to find the maximum triplet value (i, j, k) where i < j < k
long long maxTripletValue(vector<int> &nums)
{
    int n = nums.size(); // Get the size of the input vector

    // Prefix max array to keep track of maximum nums[i] for i < j
    vector<int> prefixMax(n, 0);
    prefixMax[0] = nums[0]; // Initialize the first element of the prefixMax array
    for (int i = 1; i < n; i++)
    {
        // Update prefixMax[i] with the maximum value between prefixMax[i-1] and nums[i]
        prefixMax[i] = max(prefixMax[i - 1], nums[i]);
    }

    // Suffix max array to keep track of maximum nums[k] for k > j
    vector<int> suffixMax(n, 0);
    suffixMax[n - 1] = nums[n - 1]; // Initialize the last element of the suffixMax array
    for (int k = n - 2; k >= 0; k--)
    {
        // Update suffixMax[k] with the maximum value between suffixMax[k+1] and nums[k]
        suffixMax[k] = max(suffixMax[k + 1], nums[k]);
    }

    long long maxValue = 0; // Variable to store the maximum triplet value

    // Iterate through j and find the maximum value for triplet (i, j, k)
    for (int j = 1; j < n - 1; j++)
    {
        int leftMax = prefixMax[j - 1];  // Max nums[i] where i < j
        int rightMax = suffixMax[j + 1]; // Max nums[k] where k > j

        // Calculate the triplet value using long long to prevent overflow
        long long tripletValue = (1LL * (leftMax - nums[j])) * rightMax;
        // Update maxValue with the maximum value between maxValue and tripletValue
        maxValue = max(maxValue, tripletValue);
    }

    return maxValue; // Return the maximum triplet value
}

int main()
{
    vector<int> nums = {1000000, 1, 999999, 2, 1000000}; // Example input vector
    cout << maxTripletValue(nums) << endl; // Expected output: large but valid
    return 0;
}
