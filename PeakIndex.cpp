#include <iostream>
using namespace std;

int main()
{
    int arr[1000]; // Array to store elements
    int n; // Variable to store the size of the array

    // Taking input for the array size
    cout << "Enter the size of array: ";
    cin >> n;

    // Taking input for array elements
    cout << "Enter the elements of array: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int start = 0, end = n - 1; // Defining search range for peak element

    // Implementing binary search for peak element
    while (start < end)
    {
        int mid = start + (end - start) / 2; // Calculate mid index

        // Check if mid is a peak element
        if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
        {
            cout << "Peak Element is at index: " << mid << endl;
            return 0; // Exit program after finding a peak
        }

        // Move to the side of the larger neighbor
        if (arr[mid] < arr[mid + 1])
        {
            start = mid + 1; // Shift search to the right half
        }
        else
        {
            end = mid - 1; // Shift search to the left half
        }
    }

    // After the loop, start and end converge at the peak element
    cout << "Peak Element is at index " << start << " is: " << arr[start] << endl;

    return 0;
}
