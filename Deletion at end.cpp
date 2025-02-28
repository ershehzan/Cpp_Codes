#include <iostream>
using namespace std;

int main()
{
    int n; // Variable to store the number of elements in the array
    cout << "Enter the number of elements in the array: ";
    cin >> n; // Read the number of elements from the user

    int arr[1000]; // Declare an array with a maximum size of 1000
    cout << "Enter " << n << " elements:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i]; // Read each element from the user and store it in the array
    }

    // Decrease the size of the array by 1 to delete the last element
    // This effectively removes the last element from the array
    n--;

    cout << "Array after deletion at the end: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " "; // Print each element of the array up to the new size
    }
    cout << endl; // Print a newline character at the end

    return 0; // Return 0 to indicate successful execution
}