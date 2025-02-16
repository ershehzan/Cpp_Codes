#include <iostream>  
using namespace std; 

// Main function where execution starts
int main()
{
    int i, j, key; // Declare variables for loop control and key for insertion

    // Initialize an array of size 6 with unsorted elements
    int arr[10] = {10, 41, 64, 29, 11, 9,5,7,9,11};

    // Insertion Sort Algorithm
    // Start from the second element (index 1) and move towards the last element
    for (i = 1; i < 10; i++)
    {
        key = arr[i]; // Store the current element (key) that needs to be placed correctly
        j = i - 1;    // Start comparing with the previous element

        // Move elements that are greater than 'key' one position ahead
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j]; // Shift element to the right
            j = j - 1;           // Move backward to compare previous elements
        }
        arr[j + 1] = key; // Place the key in its correct position
    }

    // Print the sorted array
   cout << "Sorted Array is: ";
    for (i = 0; i < n; i++)
    {
        cout << arr[i] << " "; // Output each sorted element separated by a space
    }

    return 0; // Indicate successful program execution
}
