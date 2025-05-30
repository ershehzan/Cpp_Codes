#include <iostream>   // For input/output operations
#include <vector>     // For using the vector container
#include <cmath>      // For using the abs() function to calculate absolute value

using namespace std;

int main() {
    int n;

    // Prompt the user to enter the size of the array
    cout << "Enter the size of array: ";
    cin >> n;

    // Declare a vector of integers with size n to store the array elements
    vector<int> arr(n);

    // Prompt the user to enter the elements of the array
    cout << "Enter the elements of array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];  // Read each element from user input
    }

    // Variables to store the sum of elements at even and odd positions
    // 'even' will hold the sum of elements at even positions (2, 4, 6, ...)
    // 'odd' will hold the sum of elements at odd positions (1, 3, 5, ...)
    int even = 0, odd = 0;

    // Loop through each element in the array
    for (int i = 0; i < n; i++) {
        // Since array indexing starts from 0, (i+1) represents the position (1-based)
        if ((i + 1) % 2 == 0) {
            // If position is even, add element to 'even' sum
            even += arr[i];
        } else {
            // If position is odd, add element to 'odd' sum
            odd += arr[i];
        }
    }

    // Calculate the absolute difference between the sums of even and odd positions
    int diff = abs(even - odd);

    // Output the result
    cout << "Output: " << diff << endl;

    return 0;   // Indicate successful program termination
}
