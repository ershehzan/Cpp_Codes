
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

    // Transpose the matrix in place
    // Iterate over the rows of 'arr'
    for (int i = 0; i < 4; i++) {
        // Iterate over the columns of 'arr' starting from the diagonal element
        for (int j = i + 1; j < 4; j++) {
            // Swap the elements to transpose the matrix in place
            swap(arr[i][j], arr[j][i]);
        }
    }

    // Print the transposed matrix
    cout << "Transposed Matrix:" << endl;
    // Iterate over the rows of the transposed 'arr'
    for (int i = 0; i < 4; i++) {
        // Iterate over the columns of the transposed 'arr'
        for (int j = 0; j < 4; j++) {
            // Print the value of 'arr' followed by a space
            cout << arr[i][j] << " ";
        }
        // Print a newline after each row
        cout << endl;
    }

    return 0;
}
