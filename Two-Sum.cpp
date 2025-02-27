#include <iostream>
using namespace std;

int main() {
    int arr[1000]; // Array to store elements (maximum size 1000)
    int n, target; // 'n' for the number of elements, 'target' for the sum we need to find

    // Taking input for the number of elements in the array
    cout << "Enter the number of elements: ";
    cin >> n;

    // Taking input for the array elements
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Taking input for the target sum
    cout << "Enter the Target: ";
    cin >> target;

    // Using a nested loop to find all pairs whose sum equals the target
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) { // j starts from i+1 to avoid duplicate pairs
            if (arr[i] + arr[j] == target) { // Check if the sum of arr[i] and arr[j] matches the target
                cout << "Pair found" << " [" << i << "," << j << "]" << endl; // Print the pair indices
            }
        }
    }

    return 0;
}
