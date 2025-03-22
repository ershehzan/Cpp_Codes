#include <iostream>
using namespace std;

int main()
{
    // Declare an array of size 1000
    int arr[1000];
    int n, i;

    // Prompt the user to enter the number of elements
    cout << "Enter the index: ";
    cin >> n;

    // Prompt the user to enter the elements of the array
    cout << "Enter the Elements: ";
    for (i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // Store the last element in a temporary variable
    int temp = arr[n - 1];

    // Shift elements to the right
    for (i = n - 1; i > 0; i--)
    {
        arr[i] = arr[i - 1];
    }

    // Place the last element at the beginning
    arr[0] = temp;

    // Print the rotated array
    cout << "Rotated array: ";
    for (i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Return 0 to indicate successful execution
    return 0;
}
