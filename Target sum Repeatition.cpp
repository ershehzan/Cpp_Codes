#include <iostream>
using namespace std;

// Function to calculate the number of ways to achieve the target sum using recursion
// Parameters:
//   arr[]: Array of integers representing available numbers
//   index: Current index in the array being processed
//   sum: Remaining target sum to achieve
//   n: Size of the array
// Returns:
//   An integer representing the number of ways to achieve the target sum
int subsum(int arr[], int index, int sum, int n) {
    // Base Case 1: If the target sum is achieved, there's exactly one way (valid solution found)
    if (sum == 0)
        return 1;
    
    // Base Case 2: If all elements are processed or the remaining sum becomes negative, no solution exists
    if (index == n || sum < 0)
        return 0;

    // Recursive Case:
    // 1. Exclude the current element and proceed to the next element
    // 2. Include the current element and reduce the remaining sum
    return subsum(arr, index + 1, sum, n) + subsum(arr, index, sum - arr[index], n);
}

int main() {
    // Sample array of integers
    int arr[] = {2, 3, 4};
    
    // Target sum to be achieved
    int sum = 6;

    // Call the function to find the target sum and print the result
    cout << "Number of ways to achieve the target sum: " << subsum(arr, 0, sum, 3) << endl;

    return 0;
}
