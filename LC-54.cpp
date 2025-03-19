#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& arr) {

        // Leet code solution Starts here
        vector<int> ans;
        int row = arr.size(), col = arr[0].size();
        int top = 0, bot = row - 1, left = 0, right = col - 1;

        while (left <= right && top <= bot) {
            // Left to Right
            for (int j = left; j <= right; j++)
                ans.push_back(arr[top][j]);
            top++;

            // Top to Bottom
            if (top <= bot) {
                for (int i = top; i <= bot; i++)
                    ans.push_back(arr[i][right]);
                right--;
            }

            // Right to Left
            if (top <= bot) { // Check to prevent duplicate row traversal
                for (int j = right; j >= left; j--)
                    ans.push_back(arr[bot][j]);
                bot--;
            }

            // Bottom to Top
            if (left <= right) { // Check to prevent duplicate column traversal
                for (int i = bot; i >= top; i--)
                    ans.push_back(arr[i][left]);
                left++;
            }
        }
        return ans;
        // Leet code solution Ends here
    }
};

int main() {
    Solution sol;
    vector<vector<int>> arr = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    vector<int> result = sol.spiralOrder(arr);

    cout << "Spiral Order: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}