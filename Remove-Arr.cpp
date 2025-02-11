#include <iostream>
using namespace std;

int main()
{
    int arr[1000]; // Array to store elements
    int n; // Variable to store the number of elements

    // Input: Get the number of elements
    cout << "Enter the number of elements: ";
    cin >> n;

    // Input: Get the elements of the array
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) 
    {
        cin >> arr[i];
    }

    int i = 0; // Index variable for iteration
    int val; // Value to be removed
    cout << "Enter the value to remove: ";
    cin >> val;

    // Loop through the array to remove occurrences of 'val'
    while (i < n)
    {
        if (arr[i] == val)
        {
            arr[i] = arr[n - 1]; // Replace current element with the last element
            n--;                 // Reduce the array size
        }
        else
        {
            i++; // Move to the next element if no replacement is done
        }
    }

    // Output the modified size and array
    cout << "New size: " << n << endl;
    cout << "Modified array: ";
    for (int i = 0; i < n; i++) // Loop to print the updated array
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
