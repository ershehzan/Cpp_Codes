// Include the iostream library for input and output operations
#include <iostream>
using namespace std;

// Recursive function to calculate the sum of elements in an array
// Parameters:
// - `arr[]`: The array containing the elements to be summed
// - `index`: The current index being processed
// - `n`: The total number of elements in the array
// Base case: When the current index equals the size of the array `n`, return 0 (end of recursion).
// Recursive case: Add the current element (arr[index]) to the result of the sum of the remaining elements.
int sum(int arr[], int index, int n)
{
    // Base case: If the index reaches the end of the array, return 0
    if (index == n)
    {
        return 0;
    }

    // Recursive case: Add the current element to the sum of the remaining elements
    return arr[index] + sum(arr, index + 1, n);
}

int main()
{
    // Initialize an array with 5 elements
    int arr[5] = {1, 2, 3, 4, 5};

    // Call the sum function with the array, starting index (0), and size of the array (5)
    // Output the result, which is the sum of all elements in the array
    cout << "Sum of all the Elements is: " << sum(arr, 0, 5) << endl;

    // Return 0 to indicate successful program completion
    return 0;
}
