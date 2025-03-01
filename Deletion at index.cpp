#include <iostream>
using namespace std;

void deleteElement(int arr[], int &size, int index) {
    if (index < 0 || index >= size) {
        cout << "Invalid index!" << endl;
        return;
    }
    for (int i = index; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    size--; // Reduce array size
}

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int size = sizeof(arr) / sizeof(arr[0]);
    int index;

    cout << "Enter the index to delete: ";
    cin >> index;

    deleteElement(arr, size, index);

    cout << "Updated array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    return 0;
}
