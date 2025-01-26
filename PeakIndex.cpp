// Lc 852

#include <iostream>
using namespace std;
int main()
{
    // int n;
    // cout << "Enter the Element to search : ";
    // cin >> n;

    int arr[] = {2, 4, 6, 8, 10, 8, 5};
    // int size = sizeof(arr) / sizeof(arr[0]);
    int start = 0, end = 6;
    while (start <= end)
    {

        int mid = end + (start - end) / 2;

        if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
        {
            cout << "Peak Element is : " << mid << endl;

            return 0;
        }

        else if (arr[mid] > arr[mid - 1])
        {
            start = mid++;
        }
        else
        {
            end = mid--;
        }
    }
    cout << "Element is not present in the array" << endl;
    return 0;
}