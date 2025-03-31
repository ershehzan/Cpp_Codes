#include <iostream>
using namespace std;

int main()
{
     int arr[1000];
    int n;
    cout << "Enter the size of array: ";
    cin >> n;
    cout << "Enter the elements of array: " << endl;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
 
    int start = 0,end=n-1;


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
    cout << "Peak Element is at index " << start <<" is : "<<arr[start]<< endl;

    return 0;
}
