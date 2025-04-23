#include <iostream>
using namespace std;
bool BinarySearch(int arr[], int x, int start, int end)
{

    if (start > end)
    {
        return 0;
    }

    int mid = start + (end - start) / 2;

    if (arr[mid] == x)
    {
        return 1;
    }
    else if (arr[mid] > x)
    {
        return BinarySearch(arr, x, start, mid - 1);
    }
    else
    {
        return BinarySearch(arr, x, mid + 1, end);
    }
}

int main()
{

    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int x;
    cout << "Enter the element to be searched: ";
    cin >> x;

    cout << BinarySearch(arr, x, 0, 9);

    return 0;
}