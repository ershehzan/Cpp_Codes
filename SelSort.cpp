#include <iostream>
using namespace std;

int main()
{
    int arr[1000]; // Declaring an array of size 1000
    int n; // Variable to store the number of elements in the array

    // Taking input for the number of elements
    cout << "Enter the Index: ";
    cin >> n;

    // Taking input for array elements
    cout << "Enter the Elements of Array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // Selection Sort Algorithm
    for (int i = 0; i < n - 1; i++)
    {
        int index = i; // Assume the current index has the smallest element

        // Find the smallest element in the unsorted portion
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[index])
                index = j; // Update index if a smaller element is found
        }

        // Swap the smallest element with the first unsorted element
        swap(arr[i], arr[index]);
    }

    // Output the sorted array
    cout << "Sorted Array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0; // End of program
}
