#include <iostream>
#include <algorithm> // To use the swap function
using namespace std;
// Function to partition the array into two segments based on the pivot
// Elements smaller than or equal to the pivot are placed to its left
// Elements greater than the pivot are placed to its right
int partition(int arr[], int start, int end){
    int pos = start; // Position to place the next smaller element

    // Iterate through the array to rearrange elements
    for (int i = start; i <= end; i++)
    {
        if (arr[i] <= arr[end]) // Compare current element with the pivot (last element)
        {
            swap(arr[i], arr[pos]); // Place the smaller element at the correct position
            pos++; // Move the position forward
        }
    }
    return pos - 1; // Return the final position of the pivot
};
// Function to implement the QuickSort algorithm
// This function sorts the array recursively
void QuickSort(int arr[], int start, int end)
{
    // Base case: If the segment has one or no elements, it is already sorted
    if (start >= end)
    {
        return;
    }

    // Partition the array and get the pivot index
    int pivot = partition(arr, start, end);

    // Recursively sort the left half (elements less than or equal to pivot)
    QuickSort(arr, start, pivot - 1);

    // Recursively sort the right half (elements greater than pivot)
    QuickSort(arr, pivot + 1, end);
};

int main(){
    // Initialize an array to be sorted
    int arr[] = {9, 7, 5, 11, 12, 2, 14, 3};
    int n = 8; // Number of elements in the array

    // Call the QuickSort function to sort the array
    QuickSort(arr, 0, n - 1);

    // Print the sorted array
    cout << "Sorted array: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}




