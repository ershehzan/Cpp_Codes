#include <iostream>
using namespace std;

int main() {
    int arr[1000], n;

    // Prompt the user to enter the size of the array
    cout << "Enter the size of the array: ";
    cin >> n;

    // Prompt the user to enter the elements of the array
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int index = 1; // Pointer for placing unique elements

    // Loop to remove duplicate elements (assuming the array is sorted)
    for (int i = 1; i < n; i++) {
        if (arr[i] != arr[i - 1]) { // Check if the current element is different from the previous one
            arr[index] = arr[i]; // Place unique element at index
            index++; // Move the pointer forward
        }
    }

    // Display the array after removing duplicates
    cout << "Array after removing duplicates: ";
    for (int i = 0; i < index; i++) {
        cout << arr[i] << " "; // Print each unique element
    }
    cout << endl;

    return 0;
}
