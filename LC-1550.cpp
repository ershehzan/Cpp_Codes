#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int n = arr.size();

        for (int i = 0; i <= n - 3; ++i) {
            if (arr[i] % 2 == 1 && arr[i + 1] % 2 == 1 && arr[i + 2] % 2 == 1) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    Solution solution;

    // Example input
    vector<int> arr;
    int n, num;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> num;
        arr.push_back(num);
    }

    // Call the function and display the result
    if (solution.threeConsecutiveOdds(arr)) {
        cout << "The array contains three consecutive odd numbers." << endl;
    } else {
        cout << "The array does not contain three consecutive odd numbers." << endl;
    }

    return 0;
}