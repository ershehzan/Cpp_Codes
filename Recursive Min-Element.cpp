// Include the iostream library for handling input and output operations
#include <iostream>
// Include the climits library to use the INT_MIN and INT_MAX macros if needed
#include <climits>
using namespace std;

// Recursive function to find the minimum element in an array
// Parameters:
// - `arr[]`: The array containing the elements
// - `index`: The current index being processed
// - `n`: The total number of elements in the array
// Base case: When the current index is the last element of the array, return the value at that index.
// Recursive case: Compare the current element (`arr[index]`) with the result of the recursive call for the remaining elements.
int minelement(int arr[], int index, int n)
{
    // Base case: If the current index is the last element, return its value
    if (index == n - 1)
    {
        return arr[index];
    }

    // Recursive case: Find the minimum between the current element
    // and the minimum of the remaining elements
    return min(arr[index], minelement(arr, index + 1, n));
}

int main()
{
    // Initialize an array with 5 elements
    int arr[5] = {1, 2, 3, 4, 5};

    // Call the recursive function `minelement` with the array,
    // starting index (0), and the size of the array (5)
    // Output the minimum element in the array
    cout << "Minimum Element is: " << minelement(arr, 0, 5) << endl;

    // Return 0 to indicate successful program termination
    return 0;
}


