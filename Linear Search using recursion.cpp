#include <iostream> // Include the iostream header for input/output operations
using namespace std; // Use the standard namespace to avoid prefixing std::

// Recursive function to perform linear search in an array
// Parameters:
// - arr: The array in which to search
// - x: The element to search for
// - index: The current index being checked in the array
bool LinearSearch(int arr[], int x, int index)
{
    // Base case: If the index reaches -1, the entire array has been searched,
    // and the element was not found
    if (index == -1)
    {
        return 0; // Return false (element not found)
    }

    // If the current element matches the element being searched for,
    // return true (element found)
    if (arr[index] == x)
    {
        return 1; // Return true
    }

    // Recursive case: Move to the previous index and continue the search
    return LinearSearch(arr, x, index - 1);
}

int main()
{
    // Initialize an array with 10 elements
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // Declare a variable to store the element to be searched
    int x;

    // Prompt the user to enter the element to search
    cout << "Enter the element to be searched: ";
    cin >> x;

    // Call the LinearSearch function and print the result
    // Parameters passed:
    // - arr: The array to search in
    // - x: The element to search for
    // - 9: The last index of the array (arr.length - 1)
    // The result (1 for found, 0 for not found) is directly printed
    cout << LinearSearch(arr, x, 9);

    return 0; // Exit the program
}
