#include <iostream>
using namespace std;

int main()
{
    // Variable declarations
    int n, l = 0, m, target;
    int arr[1000]; // Array to store user input (max size 1000)

    // Take the size of the array from the user
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    // Input elements of the array
    cout << "Enter " << n << " elements (array should be sorted for binary search to work correctly): ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // Take the target number to search
    cout << "Enter the number to search: ";
    cin >> target;

    // Set 'r' to the last index of the array
    int r = n - 1;

    // Begin binary search
    while (l <= r)
    {
        // Calculate the middle index
        m = l + (r - l) / 2; // Prevents potential integer overflow

        // If the middle element is the target, print the index and exit
        if (arr[m] == target)
        {
            cout << "Element is present at index: " << m << endl;
            return 0; // Exit the program
        }
        // If target is greater than the middle element, search in the right half
        else if (arr[m] < target)
        {
            l = m + 1;
        }
        // If target is smaller than the middle element, search in the left half
        else
        {
            r = m - 1;
        }
    }

    // If the element is not found, print the message
    cout << "Element is not present in the array." << endl;

    return 0;
}
