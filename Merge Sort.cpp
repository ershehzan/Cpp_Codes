#include <iostream>
#include <vector>
using namespace std;

void merge(int arr[], int start, int mid, int end)
{
    vector<int> temp(end - start + 1);

    int left = start, right = mid + 1, index = 0;

    while (left <= mid && right <= end)
    {

        if (arr[left] < arr[right])
        {
            temp[index] = arr[left];
            index++, left++;
        }
        else
        {
            temp[index] = arr[right];
            index++, right++;
        }
    }
    // left over elements

    while (left <= mid)
    {
        temp[index] = arr[left];
        index++, left++;
    }
    // Right lefted elements
    while (right <= end)
    {
        temp[index] = arr[right];
        index++, right++;
    }
    index = 0;
    while (start <= end)
    {
        arr[start] = temp[index];
        start++, index++;
    }
}

void mergesort(int arr[], int start, int end)
{

    int mid = start + (end - start) / 2;
    if (start == end)
    {
        return;
    }
    // Left side
    mergesort(arr, start, mid);
    // Right side
    mergesort(arr, mid + 1, end);
    merge(arr, start, mid, end);
}

int main()
{

    int arr[] = {12, 11, 13, 5, 6, 7, 34, 56, 82, 10};

    mergesort(arr, 0, 9);

    cout << "Sorted array is: \n";
    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}

