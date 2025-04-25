#include <iostream>
#include <algorithm>
using namespace std;

int partition(int arr[], int start, int end)
{

    int pos = start;

    for (int i = start; i <= end; i++)
    {
        if (arr[i] >= arr[end])
        {
            swap(arr[i], arr[pos]);
            pos++;
        }
    }
    return pos-1;
};

void QuickSort(int arr[], int start, int end)
{

    if (start >= end)
    {
        return;
    }

    int pivot = partition(arr, start, end);

    QuickSort(arr, start, pivot - 1);
    QuickSort(arr, pivot+1, end);
};
int main()
{

    int arr[] = {9, 7, 5, 11, 12, 2, 14, 3};
    int n = 8;

    QuickSort(arr, 0, n - 1);
    cout << "Sorted array: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}