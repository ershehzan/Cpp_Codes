#include <iostream>
#include <vector>
using namespace std;

// Function to merge two sorted halves of the array into a single sorted section
void merge(int arr[], int start, int mid, int end)
{
    // Temporary vector to store the merged elements
    vector<int> temp(end - start + 1);

    // Pointers for the left and right halves of the array
    int left = start, right = mid + 1, index = 0;

    // Merge elements from both halves into the temporary array
    while (left <= mid && right <= end)
    {
        if (arr[left] > arr[right])
        {
            // If the element in the left half is smaller, add it to the temp array
            temp[index] = arr[left];
            index++, left++;
        }
        else
        {
            // If the element in the right half is smaller, add it to the temp array
            temp[index] = arr[right];
            index++, right++;
        }
    }

    // Add any remaining elements from the left half
    while (left <= mid)
    {
        temp[index] = arr[left];
        index++, left++;
    }

    // Add any remaining elements from the right half
    while (right <= end)
    {
        temp[index] = arr[right];
        index++, right++;
    }

    // Copy the merged elements back into the original array
    index = 0;
    while (start <= end)
    {
        arr[start] = temp[index];
        start++, index++;
    }
}

// Function to perform merge sort on an array
void mergesort(int arr[], int start, int end)
{
    // Calculate the middle index
    int mid = start + (end - start) / 2;

    // Base case: if the segment contains only one element, return
    if (start == end)
    {
        return;
    }

    // Recursively sort the left half
    mergesort(arr, start, mid);

    // Recursively sort the right half
    mergesort(arr, mid + 1, end);

    // Merge the two sorted halves
    merge(arr, start, mid, end);
}

int main()
{
    // Input array to be sorted
    int arr[] = {12, 11, 13, 5, 6, 7, 34, 56, 82, 10};

    // Perform merge sort on the entire array
    mergesort(arr, 0, 9);

    // Print the sorted array
    cout << "Sorted array is: \n";
    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}