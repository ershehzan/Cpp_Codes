#include <iostream>
using namespace std;

// Function to perform binary search on a sorted array
int BinarySearch(int arr[], int target, int n)
{
    int start = 0, end = n - 1, mid;
    
    while (start <= end)
    {
        int mid = (start + end) / 2; // Calculate middle index
        
        if (arr[mid] == target) // If the target is found
        {
            cout << "Element found at index ";
            return mid; // Return index of the found element
        }
        else if (arr[mid] < target) // If target is greater, ignore left half
        {
            start = mid + 1;
        }
        else // If target is smaller, ignore right half
        {
            end = mid - 1;
        }
    }
    return -1; // Return -1 if the element is not found
}

int main()
{
    int arr[1000]; // Declare an array with a maximum size of 1000
    int n;
    
    // Take input for array size
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    
    // Take input for array elements
    cout << "Enter the elements of the sorted array: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int target;
    
    // Take input for the target element to search
    cout << "Enter the number to search: ";
    cin >> target;

    // Perform binary search and print the result
    int result = BinarySearch(arr, target, n);
    if (result != -1)
        cout << result << endl;
    else
        cout << "Element not found" << endl;

    return 0; // Exit program
}
