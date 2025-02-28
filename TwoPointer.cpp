#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> arr = {2, 7, 11, 15, 27};  // Sorted array
    int target = 22; // Target sum

    // Display the array elements
    for (size_t i = 0; i < arr.size(); ++i)
    {
        cout << arr[i] << " "; // Print each element of the array
    }
    cout << endl; // Print a newline character at the end

    size_t start = 0, end = arr.size() - 1; // Two pointers initialized to the beginning and end of the array

    // Two-pointer approach to find the pair
    while (start < end) {
        int sum = arr[start] + arr[end]; // Calculate the sum of the elements at the two pointers

        if (sum == target) {
            // If the sum is equal to the target, print the indices of the pair and exit
            cout << "Pair found: [" << start << "," << end << "]" << endl;
            return 0; // Exit after finding the first pair
        } 
        else if (sum > target) {
            // If the sum is greater than the target, move the 'end' pointer to the left to reduce the sum
            end--;
        } 
        else {
            // If the sum is less than the target, move the 'start' pointer to the right to increase the sum
            start++;
        }
    }

    // If no pair is found, print a message indicating that
    cout << "No pair found" << endl;
    return 0; // Return 0 to indicate successful execution
}
