#include <iostream>  // Include the iostream library for input and output operations
using namespace std; // Use the standard namespace to avoid prefixing 'std::'

// Main function where execution starts
int main()
{
    int arr[1000]; // Declare an array of size 1000 to store elements
    int n, i;      // Declare variables for storing the number of elements and loop iterator

    // Prompt the user to enter the number of elements in the array
    cout << "Enter the index: ";
    cin >> n; // Read the number of elements from the user

    // Prompt the user to enter the array elements
    cout << "Enter the Elements: ";
    for (i = 0; i < n; i++)
    {
        cin >> arr[i]; // Read each element and store it in the array
    }

    // Initialize two pointers for swapping elements to reverse the array
    int start = 0, end = n - 1;

    // Loop to reverse the array
    while (start < end)
    {
        swap(arr[start], arr[end]); // Swap the elements at 'start' and 'end' positions
        start++;  // Move the start pointer forward
        end--;    // Move the end pointer backward
    };

    // Print the reversed array
    for (int i = 0; i < n; i++)
        cout << arr[i] << " "; // Output each element separated by a space

    return 0; // Indicate that the program executed successfully
}
