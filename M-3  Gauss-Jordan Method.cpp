#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of variables: ";
    cin >> n;

    vector<vector<double>> a(n, vector<double>(n + 1));

    // Input augmented matrix
    cout << "\nEnter the augmented matrix (coefficients and constants):\n";
    for (int i = 0; i < n; ++i)
        {
        cout << "Row " << i + 1 << ": ";
        for (int j = 0; j <= n; ++j) {
            cin >> a[i][j];
        }
    }

    // Gauss-Jordan Elimination
    for (int i = 0; i < n; ++i) {
        // Make the diagonal element 1 (normalize row)
        double pivot = a[i][i];
        if (pivot == 0.0) {
            cout << "\nMathematical Error: Zero pivot found. Cannot continue.\n";
            return -1;
        }
        for (int j = 0; j <= n; ++j)
            a[i][j] /= pivot;

        // Eliminate the current column from all other rows
        for (int k = 0; k < n; ++k) {
            if (k == i) continue;
            double factor = a[k][i];
            for (int j = 0; j <= n; ++j) {
                a[k][j] -= factor * a[i][j];
            }
        }
    }

    // Output solution
    cout << "\nSolution:\n";
    cout << fixed << setprecision(6);
    for (int i = 0; i < n; ++i) {
        cout << "x" << i + 1 << " = " << a[i][n] << endl;
    }

    return 0;
}
