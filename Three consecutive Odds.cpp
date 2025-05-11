#include <iostream>
#include <vector>
using namespace std;

// Definition of the Solution class containing the method to solve the problem
class Solution {
public:
    // Method to check if the array contains three consecutive odd numbers
    bool threeConsecutiveOdds(vector<int>& arr) {
        int n = arr.size(); // Get the size of the input array

        // Iterate through the array, stopping at the third-last element
        for (int i = 0; i <= n - 3; ++i) {
            // Check if the current element and the next two elements are odd
            if (arr[i] % 2 == 1 && arr[i + 1] % 2 == 1 && arr[i + 2] % 2 == 1) {
                return true; // Return true if three consecutive odd numbers are found
            }
        }
        return false; // Return false if no such sequence is found
    }
};

int main() {
    Solution solution; // Create an instance of the Solution class

    // Input array to hold user-provided values
    vector<int> arr;
    int n, num;

    // Prompt the user to enter the number of elements in the array
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    // Prompt the user to enter the elements of the array
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> num;       // Read each element
        arr.push_back(num); // Add it to the array
    }

    // Call the function to check for three consecutive odd numbers
    // and display the result based on the return value
    if (solution.threeConsecutiveOdds(arr)) {
        cout << "The array contains three consecutive odd numbers." << endl;
    } else {
        cout << "The array does not contain three consecutive odd numbers." << endl;
    }

    return 0; // Indicate that the program ended successfully
}
