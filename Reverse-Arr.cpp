#include <iostream>
using namespace std;

int main()
{
    int arr[1000]; // Declare an array with a maximum size of 1000
    int n, i;

    // Prompt the user to enter the number of elements
    cout << "Enter the number of elements: ";
    cin >> n;

    // Prompt the user to enter the elements of the array
    cout << "Enter the elements: ";
    for (i = 0; i < n; i++)
    {
        cin >> arr[i]; // Store each element in the array
    }

    int start = 0, end = n - 1; // Initialize start and end pointers for swapping

    // Reverse the array using the two-pointer approach
    while (start < end)
    {
        swap(arr[start], arr[end]); // Swap the first and last elements
        start++;  // Move the start pointer forward
        end--;    // Move the end pointer backward
    };

    // Print the reversed array
    cout << "Reversed array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}
