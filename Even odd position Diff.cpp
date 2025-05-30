#include <iostream>
#include <vector>
#include <cmath> // for abs()

using namespace std;

int main() {
    int n;

    // Prompt the user to enter the size of the array
    cout << "Enter the size of array: ";
    cin >> n;

    // Declare a vector of size n
    vector<int> arr(n);

    // Prompt the user to enter the elements of the array
    cout << "Enter the elements of array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Variables to store the sum of even and odd positioned elements
    int even = 0, odd = 0;

    for (int i = 0; i < n; i++) {
        // Positions are considered 1-based (i+1)
        if ((i + 1) % 2 == 0) {
            even += arr[i];
        } else {
            odd += arr[i];
        }
    }

    // Calculate and print the absolute difference
    int diff = abs(even - odd);
    cout << "Output: " << diff << endl;

    return 0;
}
