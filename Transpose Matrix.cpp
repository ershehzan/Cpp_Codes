
#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Initialize a 2D vector 'arr' with predefined values
    vector<vector<int>> arr = {
        {0, 1, 2, 3},
        {4, 5, 6, 7},
        {8, 9, 10, 11},
        {12, 13, 14, 15}
    };

    // Declare a 2D array 'trans' to store the transposed matrix
    int trans[4][4];

    // Transpose the matrix
    // Iterate over the rows of 'arr'
    for (int i = 0; i < 4; i++) {
        // Iterate over the columns of 'arr'
        for (int j = 0; j < 4; j++) {
            // Assign the transposed value from 'arr' to 'trans'
            trans[j][i] = arr[i][j];
        }
    }

    // Print the transposed matrix in matrix form
    cout << "Transposed Matrix:" << endl;
    // Iterate over the rows of 'trans'
    for (int i = 0; i < 4; i++) {
        // Iterate over the columns of 'trans'
        for (int j = 0; j < 4; j++) {
            // Print the value of 'trans' followed by a space
            cout << trans[i][j] << " ";
        }
        // Print a newline after each row
        cout << endl;
    }

    return 0;
}
