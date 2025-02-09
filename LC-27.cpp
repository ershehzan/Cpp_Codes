#include <iostream>
using namespace std;

int removeElement(int arr[], int n, int val) {
    int i = 0;
    while (i < n) {
        if (arr[i] == val) {
            arr[i] = arr[n - 1]; // Swap with last element
            n--; // Reduce size
        } else {
            i++; // Move to next element
        }
    }
    return n;
}

int main() {
    int arr[] = {3, 2, 2, 3};
    int val = 3;
    int n = sizeof(arr) / sizeof(arr[0]);
    
    int newSize = removeElement(arr, n, val);
    
    cout << "New size: " << newSize << "\n";
    cout << "Modified array: ";
    for (int i = 0; i < newSize; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    return 0;
}