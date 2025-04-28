// Include necessary header files
#include <iostream> // For input/output operations
using namespace std;

// Function to determine if a subset with the given target sum exists
// Parameters:
// - arr[]: The input array of integers
// - index: The current index being processed in the array
// - n: The total number of elements in the array
// - target: The target sum to be achieved
// Returns:
// - true (1) if a subset with the target sum exists, false (0) otherwise
bool find(int arr[], int index, int n, int target)
{
    // Base case 1: The target sum is exactly 0, meaning the subset is found
    if (target == 0)
    {
        return 1; // Return true
    }

    // Base case 2: All elements are processed (index == n) or target becomes negative
    if (index == n || target < 0)
    {
        return 0; // Return false
    }

    // Recursive case:
    // 1. Exclude the current element and move to the next index
    // 2. Include the current element in the subset and reduce the target by its value
    return find(arr, index + 1, n, target) || find(arr, index + 1, n, target - arr[index]);
}

int main()
{
    // Input array of integers
    int arr[] = {1, 2, 3, 4};
    int n = 4;       // Number of elements in the array
    int target = 8;  // Target sum to find

    // Call the function and print the result
    // The function returns 1 if a subset with the target sum exists, otherwise 0
    cout << find(arr, 0, n, target);

    return 0; // Indicate successful program termination
}
