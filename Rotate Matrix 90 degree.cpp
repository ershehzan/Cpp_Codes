
#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Initialize a 2D vector 'matrix' with predefined values
    vector<vector<int>> matrix = {
        {0, 1, 2, 3},
        {4, 5, 6, 7},
        {8, 9, 10, 11},
        {12, 13, 14, 15}
    };

    // Get the size of the matrix
    int n = matrix.size();

    // Declare a 2D array 'ans' to store the rotated matrix
    int ans[n][n];

    // Rotate the matrix by 90 degrees
    // Iterate over the rows of 'matrix'
    for (int i = 0; i < n; i++) {
        // Iterate over the columns of 'matrix'
        for (int j = 0; j < n; j++) {
            // Assign the rotated value from 'matrix' to 'ans'
            ans[j][n - 1 - i] = matrix[i][j];
        }
    }

    // Print the rotated matrix
    cout << "Matrix after 90 degree rotation:" << endl;
    // Iterate over the rows of 'ans'
    for (int i = 0; i < 4; i++) {
        // Iterate over the columns of 'ans'
        for (int j = 0; j < 4; j++) {
            // Print the value of 'ans' followed by a space
            cout << ans[i][j] << " ";
        }
        // Print a newline after each row
        cout << endl;
    }

    return 0;
}
