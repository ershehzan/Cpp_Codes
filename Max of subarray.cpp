// Kadane's Algorithm
// Given an array arr of N integers. Find the contiguous sub-array with maximum sum.

#include <iostream>
#include <climits>
using namespace std;
int main()
{
    int arr[1000] = {1, 2, -3, 5, 6, 9, -10};
    int n = 7;

    long long maxi = INT_MIN, prefix = 0;

    for (int i = 0; i < n; i++)
    {
        prefix += arr[i];

        maxi = max(maxi, prefix);
        if (prefix < 0)
        {
            prefix = 0;
        }
    }
cout<<"MAX value of subarray: "<<maxi;
    return 0;
}