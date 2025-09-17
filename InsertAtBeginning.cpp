#include <iostream>  
using namespace std;

int main(){
    int arr[1000];  // Declare an array with a maximum size of 1000
    int n;          // Variable to store the size of the array

    // Taking input for array size
    cout << "Enter the Index of array: ";
    cin >> n;

    // Taking input for array elements
    cout << "Enter the element:";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int newElement;  // Variable to store the new element to be inserted

    // Taking input for the new element to be inserted at the beginning
    cout << "Enter the element to insert at the beginning: ";
    cin >> newElement;

    int previous = arr[0];  // Store the first element before overwriting
    arr[0] = newElement;    // Place the new element at the first position

    // Shift all elements one position to the right
    for (int i = 1; i <= n; i++)
    {
        int temp = arr[i];  // Store the current element in a temporary variable
        arr[i] = previous;  // Shift the previous element to the current position
        previous = temp;     // Update previous for the next iteration
    }

    n++;  // Increase the size of the array by 1

    // Display the array after insertion
    cout << "Array after insertion: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}

