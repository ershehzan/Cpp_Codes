#include <iostream>
#include <climits> // For INT_MIN
using namespace std;

int main()
{
    // Declare an array of size 1000, but using only the first 8 elements
    int arr[1000] = {9, 5, 8, 12, 2, 3, 7, 4};
    int n = 8; // Size of the array

    // Initialize suffix with the last element of the array (this will track the maximum value from the right)
    int suffix = arr[n - 1];

    // Initialize ans with the smallest possible integer value
    int ans = INT_MIN;

    // Iterate from the second last element to the first element
    for (int i = n - 2; i >= 0; i--)
    {
        // Update ans with the maximum difference found so far (suffix - current element)
        ans = max(ans, suffix - arr[i]);

        // Update suffix to store the maximum value encountered so far from the right
        suffix = max(suffix, arr[i]);
    }

    // Print the maximum difference found
    cout << "Max difference between two elements: " << ans;

    return 0;
}
