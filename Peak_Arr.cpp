#include <iostream>
using namespace std;

int main()
{
   
    int arr[1000]; // Declare an array of size 1000
     int n, i;
    cout << "Enter the index: ";
    cin >> n; // Read the number of elements

    cout << "Enter the Elements: ";
    for (i = 0; i < n; i++)
    {
        cin >> arr[i]; // Read the array elements
    }

    int start = 0, end = n - 1; // Initialize start and end pointers for binary search

    while (start < end)
    {
        int mid = start + (end - start) / 2; // Calculate mid to avoid integer overflow

        // Check if mid is the peak element (greater than both neighbors)
        if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
        {
            cout << "Peak Element is at index: " << mid << endl;
            return 0; // Exit after finding the peak
        }

        // Move to the side where a greater element exists
        if (arr[mid] < arr[mid + 1])
        {
            start = mid + 1; // Move right
        }
        else
        {
            end = mid - 1; // Move left
        }
    }

    // After the loop, start and end converge at the peak element
    cout << "Peak Element is at index " << start << " is : " << arr[start] << endl;

    return 0;
}
