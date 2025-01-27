// Search in Rotated Array
// Leet code 33
#include <iostream>
using namespace std;
int main()
{

    int arr[1000] = {4, 5, 6, 7, 0, 1, 2};
    int start = 0, end = 5, mid, target = -1;

    while (start <= end)
    {
        mid = start + (end - start) / 2;

        if (arr[mid] == target)
            return mid;

        // Determine if the left half is sorted
        if (arr[mid] >= arr[start])
        {
            // Target lies within the sorted left half
            if (arr[start] <= target && arr[mid] > target)
                end = mid - 1;
            else
                start = mid + 1;
        }
        // Otherwise, the right half is sorted
        else
        {
            // Target lies within the sorted right half
            if (arr[mid] < target && target <= arr[end])
                start = mid + 1;
            else
                end = mid - 1;
        }
    }
    cout << target << " ";
    return 0;
}