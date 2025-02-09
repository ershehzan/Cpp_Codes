#include <iostream>
using namespace std;

// Function to remove all occurrences of 'val' from the array
int removeElement(int arr[], int n, int val) {
    int i = 0;
    while (i < n) {
        if (arr[i] == val) {
            arr[i] = arr[n - 1]; // Swap the current element with the last element
            n--; // Reduce the array size since the last element is removed
        } else {
            i++; // Move to the next element if no match
        }
    }
    return n; // Return the new size of the array after removal
}

int main() {
    int arr[] = {3, 2, 2, 3}; // Initial array
    int val = 3; // Element to be removed
    int n = sizeof(arr) / sizeof(arr[0]); // Calculate the size of the array
    
    int newSize = removeElement(arr, n, val); // Call function to remove 'val' from array
    
    // Print the new size of the modified array
    cout << "New size: " << newSize << "\n";
    
    // Print the modified array
    cout << "Modified array: ";
    for (int i = 0; i < newSize; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    return 0; // Exit program
}
