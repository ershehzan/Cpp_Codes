#include <iostream>
using namespace std;

int main() {
    int arr[1000] = {3, 4, 6, 8, 11, 12, 34, 41}; // Array to store elements
    int n = 8, target;

    cout << "Enter the target: ";
    cin >> target;

    int start = 0, end = n - 1;

    // Two-pointer approach to find pairs that sum up to the target
    while (start < end) {
        int sum = arr[start] + arr[end];

        if (sum == target) {
            cout << "Pair found: [" << start << "," << end << "]" << endl;
            return 0;
        } else if (sum > target) {
            end--;
        } else {
            start++;
        }
    }

    cout << "No pairs found." << endl;
    return 0;
}