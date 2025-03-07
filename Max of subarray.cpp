// Kadane's Algorithm
// Given an array arr of N integers. Find the contiguous sub-array with maximum sum.

#include <iostream>
#include <climits> // For INT_MIN
using namespace std;

int main()
{
    // Declare an array of size 1000, but only using first 7 elements
    int arr[1000] = {1, 2, -3, 5, 6, 9, -10};
    int n = 7; // Size of the used portion of the array

    // Initialize variables
    long long maxi = INT_MIN; // Stores the maximum sum found so far
    long long prefix = 0;     // Stores the running sum of the subarray

    // Iterate through the array
    for (int i = 0; i < n; i++)
    {
        prefix += arr[i]; // Add the current element to the running sum

        maxi = max(maxi, prefix); // Update the maximum sum found so far

        // If prefix sum becomes negative, reset it to 0
        // Since a negative sum would not contribute to a larger sum in future elements
        if (prefix < 0)
        {
            prefix = 0;
        }
    }

    // Print the maximum sum found
    cout << " MAX value of subarray: " << maxi;
    
    return 0;
}
