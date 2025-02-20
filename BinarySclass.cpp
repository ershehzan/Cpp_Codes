#include <iostream>
#include <algorithm> // For sorting the array
using namespace std;

// Function to perform binary search
int binarySearch(int arr[], int n, int target)
{
    int left = 0, right = n - 1, mid;

    while (left <= right)
    {
        mid = left + (right - left) / 2; // Avoids potential integer overflow

        if (arr[mid] == target)
        {
            return mid; // Element found, return index
        }
        else if (arr[mid] < target)
        {
            left = mid + 1; // Search in the right half
        }
        else
        {
            right = mid - 1; // Search in the left half
        }
    }
    return -1; // Element not found
}

int main()
{
    int n, target;
    int arr[1000]; // Maximum size of array

    cout << "Enter the number of elements in the array: ";
    cin >> n;

    cout << "Enter " << n << " elements (sorted order recommended for correct results): ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // Ensure the array is sorted before searching
    sort(arr, arr + n);
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Enter the number to search: ";
    cin >> target;

    // Perform binary search
    int result = binarySearch(arr, n, target);

    if (result != -1)
    {
        cout << "Element is present at index: " << result << endl;
    }
    else
    {
        cout << "Element is not present in the array." << endl;
    }

    return 0;
}
