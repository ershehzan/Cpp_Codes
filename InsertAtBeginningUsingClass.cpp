#include <iostream>
using namespace std;

void insertAtBeginning(int arr[], int &n, int element) {
    // Shift elements to the right
    for (int i = n; i > 0; i--) {
        arr[i] = arr[i - 1];
    }
    // Insert the new element at the beginning
    arr[0] = element;
    n++; // Increment the size of the array
}

int main() {
    int arr[100] = {10, 20, 30, 40}; // Initial array with 4 elements
    int n = 4; // Current number of elements in the array

    cout << "Array before insertion: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    int newElement = 5; // Element to be inserted at the beginning
    insertAtBeginning(arr, n, newElement);

    cout << "Array after insertion: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}