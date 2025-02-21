// Insertion Sort Algorithm Implementation in C++
#include <iostream>
using namespace std;

// Main function where execution starts
int main()
{
    int n, key; // Declare variables: 'n' for array size, 'key' for sorting
    int arr[1000]; // Declare an array of size 1000 to store user input

    // Prompt the user to enter the number of elements in the array
    cout << "Enter the Index: ";
    cin >> n; // Read the number of elements from user input

    // Prompt the user to enter the array elements
    cout << "Enter the elements of array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i]; // Read each element and store it in the array
    }

    // Insertion Sort Algorithm
    for (int i = 1; i < n; i++) // Start from the second element (index 1) to the last
    {
        key = arr[i]; // Store the current element (key) to be placed correctly
        int j = i - 1; // Start comparing with the previous element

        // Shift elements that are greater than 'key' one position ahead
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j]; // Move the larger element one step forward
            j = j - 1; // Move backward to compare previous elements
        }
        arr[j + 1] = key; // Place 'key' in its correct position
    }

    // Print the sorted array
    cout << "Sorted Array is: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " "; // Output each sorted element separated by a space
    }

    return 0; // Program ends successfully
}
