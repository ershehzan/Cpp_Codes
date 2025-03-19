#include <iostream>
#include <vector>
using namespace std;

// Define a class named Solution
class Solution {
public:
    // Function to return the elements of a 2D matrix in spiral order
    vector<int> spiralOrder(vector<vector<int>>& arr) {

        // Initialize a vector to store the result
        vector<int> ans;
        // Get the number of rows and columns in the matrix
        int row = arr.size(), col = arr[0].size();
        // Initialize variables to keep track of the boundaries of the matrix
        int top = 0, bot = row - 1, left = 0, right = col - 1;

        // Loop until we have traversed all elements in the matrix
        while (left <= right && top <= bot) {
            // Traverse from left to right along the top boundary
            for (int j = left; j <= right; j++)
                ans.push_back(arr[top][j]);
            // Move the top boundary down
            top++;

            // Traverse from top to bottom along the right boundary
            if (top <= bot) {
                for (int i = top; i <= bot; i++)
                    ans.push_back(arr[i][right]);
                // Move the right boundary left
                right--;
            }

            // Traverse from right to left along the bottom boundary
            if (top <= bot) { // Check to prevent duplicate row traversal
                for (int j = right; j >= left; j--)
                    ans.push_back(arr[bot][j]);
                // Move the bottom boundary up
                bot--;
            }

            // Traverse from bottom to top along the left boundary
            if (left <= right) { // Check to prevent duplicate column traversal
                for (int i = bot; i >= top; i--)
                    ans.push_back(arr[i][left]);
                // Move the left boundary right
                left++;
            }
        }
        // Return the result vector containing the elements in spiral order
        return ans;
    }
};

int main() {
    // Create an instance of the Solution class
    Solution sol;
    // Initialize a 2D vector (matrix) with some values
    vector<vector<int>> arr = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    // Call the spiralOrder function and store the result
    vector<int> result = sol.spiralOrder(arr);

    // Print the elements of the result vector in spiral order
    cout << "Spiral Order: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0; 
}
