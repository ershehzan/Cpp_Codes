#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<vector<int>> arr = {
        {0, 1, 2, 3},
        {4, 5, 6, 7},
        {8, 9, 10, 11},
        {12, 13, 14, 15}
    };
    int trans[4][4];

    // Transpose the matrix
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            trans[j][i] = arr[i][j];
        }
    }

    // Print the transposed matrix in matrix form
    cout << "Transposed Matrix:" << endl;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cout << trans[i][j] << " ";
        }
        cout << endl; // Print a newline after each row
    }

    return 0;
}
