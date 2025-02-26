#include <iostream>  // Include the iostream library for input/output operations
using namespace std;

int main()
{
    // Define an array (rotated sorted array)
    int arr[1000] = {4, 5, 6, 7, 8, 10, 1, 2}; 
    int start = 0, end = 7;  // Define the search range (0 to 7 for 8 elements)
    int ans = arr[0];  // Initialize answer with the first element

    // Binary search to find the minimum element
    while (start <= end)
    {
        int mid = start + (end - start) / 2; // To avoid integer overflow

        // If mid element is greater than or equal to the first element,
        // it means the smallest element is in the right half.
        if (arr[mid] >= arr[0])
        {
            start = mid + 1;
        }
        else
        {
            // Update the minimum answer and search in the left half
            ans = arr[mid];
            end = mid - 1;
        }
    }

    // Print the minimum element found in the rotated sorted array
    cout << "Minimum element in rotated array is " << ans << endl;

    return 0; // Indicate successful program execution
}
