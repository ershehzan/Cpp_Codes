#include <iostream>
using namespace std;

// Function to calculate the number of subsets with a given sum
// Parameters:
//   arr[]: Array of integers representing the set
//   index: Current index in the array being processed
//   sum: The target sum that we are trying to achieve
//   n: The size of the array
// Returns:
//   An integer representing the number of subsets that sum up to the target value
int subsum(int arr[], int index, int sum, int n) {
    // Base Case 1: If the target sum is achieved, there is exactly one valid subset
    if (sum == 0)
        return 1;

    // Base Case 2: If we've processed all elements or the remaining sum becomes negative, no valid subset exists
    if (index == n || sum < 0)
        return 0;

    // Recursive Case:
    // 1. Exclude the current element and move to the next index
    // 2. Include the current element in the subset and reduce the target sum
    return subsum(arr, index + 1, sum, n) + subsum(arr, index, sum - arr[index], n);
}

int main() {
    // Input array representing the set
    int arr[] = {2, 3, 4};

    // Target sum to achieve
    int sum = 6;

    // Call the function and display the result
    // The result represents the number of subsets that sum up to the target value
    cout << "Number of subsets with sum " << sum << ": " << subsum(arr, 0, sum, 3) << endl;

    return 0;
}
