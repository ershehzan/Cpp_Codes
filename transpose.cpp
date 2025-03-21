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

    // Transpose the matrix
    for (int i = 0; i < 4; i++) {
        for (int j = i + 1; j < 4; j++) {
            swap(arr[i][j], arr[j][i]);
        }
    }

    // Print the transposed matrix
    cout << "Transposed Matrix:" << endl;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}