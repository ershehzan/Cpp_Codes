#include <iostream>
using namespace std;

int main()
{
    int arr[1000]; // Array to store elements
    int n; // Variable to store number of elements
    
    cout << "Enter the size of array: ";
    cin >> n;
    
    cout << "Enter the elements of array: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i]; // Taking input for array elements
    }

    // Bubble Sort Algorithm (Optimized)
    for (int i = n - 2; i >= 0; i--) // Outer loop for passes
    {
        bool swapped = false; // Flag to track swapping
        for (int j = 0; j <= i; j++) // Inner loop for comparisons
        {
            if (arr[j] > arr[j + 1]) // Swap if current element is greater than the next
            {
                swap(arr[j], arr[j + 1]);
                swapped = true; // Mark as swapped
            }
        }
        if (!swapped) // If no swaps in a pass, array is already sorted
            break;
    }

    // Displaying the sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
