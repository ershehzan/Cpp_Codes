#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void permute(vector<int>& arr, vector<vector<int>>& ans, int index) {
        if (arr.size() == index) {
            ans.push_back(arr); // Correct: pushing a vector<int> into vector<vector<int>>
            return;
        }

        for (int i = index; i < arr.size(); i++) {
            swap(arr[index], arr[i]);
            permute(arr, ans, index + 1);
            swap(arr[index], arr[i]); // backtrack
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        permute(nums, ans, 0);
        return ans;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 2, 3}; // Example input
    vector<vector<int>> result = solution.permute(nums);

    cout << "Permutations of the array are:" << endl;
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}