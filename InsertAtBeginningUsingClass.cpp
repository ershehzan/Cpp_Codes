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
   int arr[1000];
    int n;
    cout << "Enter the index of array: ";
    cin >> n;

    cout << "Array before insertion: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

  int newElement; // Element to be inserted at the beginning
    cout << "Enter the element to be inserted: ";
    cin >> newElement;
    insertAtBeginning(arr, n, newElement);

    cout << "Array after insertion: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
