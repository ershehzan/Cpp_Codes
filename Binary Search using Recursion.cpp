#include <iostream> // Include the iostream header for input/output operations
using namespace std; // Use the standard namespace to avoid prefixing std::

// Recursive function to perform binary search in a sorted array
// Parameters:
// - arr: The sorted array in which to search
// - x: The element to search for
// - start: The starting index of the search range
// - end: The ending index of the search range

bool BinarySearch(int arr[], int x, int start, int end)
{
    // Base case: If the start index exceeds the end index,
    // the element is not present in the array
    if (start > end)
    {
        return 0; // Return false (element not found)
    }

    // Calculate the middle index of the current search range
    int mid = start + (end - start) / 2;

    // If the element at the middle index matches the element being searched for,
    // return true (element found)
    if (arr[mid] == x)
    {
        return 1; // Return true
    }
    // If the element at the middle index is greater than the element being searched for,
    // recursively search the left half of the array
    else if (arr[mid] > x)
    {
        return BinarySearch(arr, x, start, mid - 1);
    }
    // Otherwise, recursively search the right half of the array
    else
    {
        return BinarySearch(arr, x, mid + 1, end);
    }
}

int main()
{
    // Declare and initialize a sorted array with 10 elements
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // Declare a variable to store the element to be searched
    int x;

    // Prompt the user to enter the element to search
    cout << "Enter the element to be searched: ";
    cin >> x;

    // Call the BinarySearch function and print the result
    // Parameters passed:
    // - arr: The sorted array to search in
    // - x: The element to search for
    // - 0: The starting index of the array
    // - 9: The last index of the array (arr.length - 1)
    // The result (1 for found, 0 for not found) is directly printed
    cout << BinarySearch(arr, x, 0, 9);

    return 0; // Exit the program
}

