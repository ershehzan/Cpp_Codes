#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Function to check if the array has any duplicate elements
    bool hasDuplicates(const vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                if (nums[i] == nums[j]) {
                    return true;
                }
            }
        }
        return false;
    }

    int minimumOperations(vector<int>& nums) {
        int operations = 0;

        while (hasDuplicates(nums)) {
            if (nums.size() <= 3) {
                nums.clear();
            } else {
                nums.erase(nums.begin(), nums.begin() + 3);
            }
            operations++;
        }

        return operations;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 2, 3, 1, 4, 5, 6, 2};

    cout << "Initial array: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    int result = solution.minimumOperations(nums);

    cout << "Minimum operations to remove duplicates: " << result << endl;

    cout << "Final array: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}