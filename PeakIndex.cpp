#include <iostream>
using namespace std;

int main()
{
    int arr[] = {2, 4, 6, 8, 10, 8, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    int start = 0, end = size - 1;

    while (start < end)
    {
        int mid = start + (end - start) / 2;

        // Check if mid is the peak element
        if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
        {
            cout << "Peak Element is at index: " << mid << endl;
            return 0;
        }

        // Move to the side of the larger neighbor
        if (arr[mid] < arr[mid + 1])
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }

    // After the loop, start and end converge at the peak element
    cout << "Peak Element is at index: " << start << endl;

    return 0;
}
