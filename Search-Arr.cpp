#include <iostream>
using namespace std;

int searchInRotatedArray(int arr[], int size, int target)
{
    int start = 0, end = size - 1, mid;

    while (start <= end)
    {
        mid = start + (end - start) / 2;

        if (arr[mid] == target)
            return mid;

        // Determine if the left half is sorted
        if (arr[start] <= arr[mid])
        {
            if (arr[start] <= target && target < arr[mid])
                end = mid - 1;
            else
                start = mid + 1;
        }
        else
        { // Right half is sorted
            if (arr[mid] < target && target <= arr[end])
                start = mid + 1;
            else
                end = mid - 1;
        }
    }
    return -1; // Target not found
}

int main()
{
    int arr[] = {4, 5, 6, 7, 0, 1, 2};
    int target;

    cout << "Enter the Target: ";
    cin >> target;

    int index = searchInRotatedArray(arr, 7, target);

    if (index != -1)
        cout << "Target found at index: " << index << endl;
    else
        cout << "Target not found" << endl;

    return 0;
}
