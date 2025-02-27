#include <iostream>
using namespace std;

int main() {
    int n;
    // Prompt user to enter the number of elements in the array
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int arr[n];  // Declare an array of size n

    // Take input for the array elements
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Initialize two pointers: 'start' at the beginning and 'end' at the last index
    int start = 0, end = n - 1;

    // Use two-pointer approach to move all zeros to the right
    while (start < end) {
        if (arr[start] == 0) {
            // If the current element at 'start' is zero, move the pointer forward
            start++;
        } 
        else if (arr[end] == 0) {
            // If the element at 'end' is zero, swap it with the non-zero element at 'start'
            swap(arr[start], arr[end]);
            start++;  // Move the start pointer ahead
        } 
        else {
            // If the element at 'end' is already non-zero, move the end pointer left
            end--;
        }
    }

    // Print the final array after moving zeros to the right
    cout << "Array after moving zeros to the right: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
