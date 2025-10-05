#include <iostream>
using namespace std;

int main() {
    // Initialize the array
    int arr[] = {10, 20, 30, 40, 50};
    int size = sizeof(arr) / sizeof(arr[0]); // Calculate the size of the array
    int index;

    // Prompt user to enter the index to delete
    cout << "Enter the index to delete: ";
    cin >> index;

    // Check if the entered index is valid
    if (index < 0 || index >= size) {
        cout << "Invalid index!" << endl;
        return 1;
    }
    
    // Shift elements to the left to overwrite the deleted element
    for (int i = index; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    size--; // Reduce the array size

    // Print the updated array
    cout << "Updated array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
