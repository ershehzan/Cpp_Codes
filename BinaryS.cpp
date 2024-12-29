#include <iostream>
using namespace std;

int BinarySearch(int arr[], int key, int n)
{
    int start = 0, end = n - 1, mid;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (arr[mid] == key)
        {
            cout << "Element found at index ";
            return mid;
        }
        else if (arr[mid] < key)
        {

            start = mid + 1;
        }
        else
        {

            end = mid - 1;
        }
    }
    return -1;
}

int main()
{
    int arr[1000];
    int n;
    cout << "Enter the index of array : ";
    cin >> n;
    cout << "Enter the elements of array : ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int key;
    cout << "Enter the number to search : " << endl;
    cin >> key;

    cout << BinarySearch(arr, key, n) << endl;
    return 0;
}