#include <iostream> // Include input-output stream library
using namespace std;

// Function to search for a target element in a rotated sorted array
int searchInRotatedArray(int arr[], int size, int target)
{
    int start = 0, end = size - 1, mid;

    // Binary search loop
    while (start <= end)
    {
        mid = start + (end - start) / 2; // Calculate the middle index to avoid overflow

        // Check if the middle element is the target
        if (arr[mid] == target)
            return mid; // Return the index if found

        // Check if the left half is sorted
        if (arr[start] <= arr[mid])
        {
            // Check if the target lies within the left half
            if (arr[start] <= target && target < arr[mid])
                end = mid - 1; // Narrow the search to the left half
            else
                start = mid + 1; // Narrow the search to the right half
        }
        else
        { // Otherwise, the right half is sorted
            // Check if the target lies within the right half
            if (arr[mid] < target && target <= arr[end])
                start = mid + 1; // Narrow the search to the right half
            else
                end = mid - 1; // Narrow the search to the left half
        }
    }
    return -1; // Target not found
}

int main()
{
    // Define a rotated sorted array
    int arr[] = {4, 5, 6, 7, 0, 1, 2};
    int target;

    // Ask the user for the target value to search for
    cout << "Enter the Target: ";
    cin >> target;

    // Call the search function
    int index = searchInRotatedArray(arr, 7, target);

    // Output the result
    if (index != -1)
        cout << "Target found at index: " << index << endl;
    else
        cout << "Target not found" << endl;

    return 0; // End the program
}
