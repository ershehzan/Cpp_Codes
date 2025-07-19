#include <iostream>
using namespace std;

// Function to perform Strassen multiplication on 2x2 matrices
void strassenMultiply(int A[2][2], int B[2][2], int C[2][2]) {
    int M1 = (A[0][0] + A[1][1]) * (B[0][0] + B[1][1]);
    int M2 = (A[1][0] + A[1][1]) * B[0][0];
    int M3 = A[0][0] * (B[0][1] - B[1][1]);
    int M4 = A[1][1] * (B[1][0] - B[0][0]);
    int M5 = (A[0][0] + A[0][1]) * B[1][1];
    int M6 = (A[1][0] - A[0][0]) * (B[0][0] + B[0][1]);
    int M7 = (A[0][1] - A[1][1]) * (B[1][0] + B[1][1]);

    C[0][0] = M1 + M4 - M5 + M7;
    C[0][1] = M3 + M5;
    C[1][0] = M2 + M4;
    C[1][1] = M1 - M2 + M3 + M6;
}

int main() {
    int A[2][2], B[2][2], C[2][2];

    cout << "Enter elements of Matrix A (2x2):\n";
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 2; ++j)
            cin >> A[i][j];

    cout << "Enter elements of Matrix B (2x2):\n";
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 2; ++j)
            cin >> B[i][j];

    strassenMultiply(A, B, C);

    cout << "Result of Strassen Matrix Multiplication (2x2):\n";
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j)
            cout << C[i][j] << " ";
        cout << endl;
    }

    return 0;
}
