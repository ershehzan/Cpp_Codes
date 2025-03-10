#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    // Initialize a vector with unsorted elements
    vector<int> arr = {1, 8, 6, 4, 10, 45};

    int x; // Variable to store the target sum
    cout << "Enter the target sum: ";
    cin >> x;

    int n = arr.size(); // Get the size of the vector

    // Sort the array to use the two-pointer approach effectively
    sort(arr.begin(), arr.end());

    // Iterate through the array, fixing one element at a time
    for (int i = 0; i < n - 2; i++) {
        int target = x - arr[i]; // Remaining sum to find

        // Two-pointer approach to find the required pair
        int start = i + 1, end = n - 1;

        while (start < end) {
            int sum = arr[start] + arr[end]; // Sum of two remaining elements

            if (sum == target) {  // If we found a triplet
                cout << "Triplet found: [" << arr[i] << ", " << arr[start] << ", " << arr[end] << "]" << endl;
                return 0; // Exit after finding the first valid triplet
            } 
            else if (sum < target) { // If sum is less, move the start pointer forward
                start++;
            } 
            else { // If sum is greater, move the end pointer backward
                end--;
            }
        }
    }

    // If no triplet is found
    cout << "No triplet found." << endl;
    return 0;
}
