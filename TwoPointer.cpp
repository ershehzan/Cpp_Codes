#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> arr = {2, 7, 11, 15, 27};  // Sorted array
    int target = 22; // Target sum

    // Display the array elements
    for (size_t i = 0; i < arr.size(); ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    size_t start = 0, end = arr.size() - 1; // Two pointers

    // Two-pointer approach to find the pair
    while (start < end) {
        int sum = arr[start] + arr[end];

        if (sum == target) {
            cout << "Pair found: [" << start << "," << end << "]" << endl;
            return 0; // Exit after finding the first pair
        } 
        else if (sum > target) {
            end--; // Decrease 'end' to reduce sum
        } 
        else {
            start++; // Increase 'start' to increase sum
        }
    }

    cout << "No pair found" << endl;
    return 0;
}