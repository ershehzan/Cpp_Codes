#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of variables: ";
    cin >> n;

    vector<vector<double>> a(n, vector<double>(n + 1)); // Augmented matrix
    vector<double> x(n); // Solution vector

    // Input coefficients and constants
    cout << "\nEnter the augmented matrix (coefficients and constants):\n";
    for (int i = 0; i < n; ++i) {
        cout << "Row " << i + 1 << ": ";
        for (int j = 0; j <= n; ++j) {
            cin >> a[i][j];
        }
    }

    // Forward Elimination
    for (int i = 0; i < n; ++i) {
        // Check for zero pivot
        if (a[i][i] == 0.0) {
            cout << "\nMathematical Error: Zero pivot encountered.\n";
            return -1;
        }

        // Eliminate lower rows
        for (int j = i + 1; j < n; ++j) {
            double ratio = a[j][i] / a[i][i];
            for (int k = 0; k <= n; ++k) {
                a[j][k] -= ratio * a[i][k];
            }
        }
    }

    // Back Substitution
    for (int i = n - 1; i >= 0; --i) {
        x[i] = a[i][n];
        for (int j = i + 1; j < n; ++j) {
            x[i] -= a[i][j] * x[j];
        }
        x[i] /= a[i][i];
    }

    // Output solution
    cout << "\nSolution:\n";
    cout << fixed << setprecision(6);
    for (int i = 0; i < n; ++i) {
        cout << "x" << i + 1 << " = " << x[i] << endl;
    }

    return 0;
}
