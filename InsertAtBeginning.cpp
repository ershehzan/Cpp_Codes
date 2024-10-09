#include <iostream>
using namespace std;

int main() {
    int arr[10] = {2, 3, 4, 5, 6};  // elements
    int n = 5;  
    int newElement;

    cout << "Enter the element to insert at the beginning: ";
    cin >> newElement;

    int previous = arr[0];
    arr[0] = newElement;


    for (int i = 1; i <= n; i++) {
       
        int temp = arr[i];
        arr[i] = previous;
        previous = temp;
    }

    n++;

    cout << "Array after insertion: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}