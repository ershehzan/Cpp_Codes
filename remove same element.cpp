#include <iostream>
using namespace std;

int main() {
    int arr[1000], n;
    cout << "Enter the size of the array: ";
    cin >> n;
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int index = 1; // Pointer for placing unique elements

    // Loop to remove duplicate elements
    for (int i = 1; i < n; i++) {
        if (arr[i] != arr[i - 1]) {
            arr[index] = arr[i]; // Place unique element at index
            index++;
        }
    }

    cout << "Array after removing duplicates: ";
    for (int i = 0; i < index; i++) {
        cout << arr[i] << " "; // Print each unique element
    }
    cout << endl;

    return 0;
}