#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of variables: ";
    cin >> n;

    // Create an augmented matrix of size n x (n+1)
    // Each row contains n coefficients and 1 constant (right-hand side)
    vector<vector<double>> a(n, vector<double>(n + 1));
    // Vector to store the solution of the system
    vector<double> x(n);

    // Input: Read the augmented matrix from the user
    cout << "\nEnter the augmented matrix (coefficients and constants):\n";
    for (int i = 0; i < n; ++i) {
        cout << "Row " << i + 1 << ": ";
        for (int j = 0; j <= n; ++j) {
            cin >> a[i][j];
        }
    }

    // Forward Elimination Process
    // Convert the matrix to upper triangular form
    for (int i = 0; i < n; ++i) {
        // Check for zero pivot element (diagonal element)
        if (a[i][i] == 0.0) {
            cout << "\nMathematical Error: Zero pivot encountered.\n";
            return -1; // Exit if zero pivot found
        }

        // Eliminate elements below the pivot in the current column
        for (int j = i + 1; j < n; ++j) {
            double ratio = a[j][i] / a[i][i]; // Multiplier for the row
            for (int k = 0; k <= n; ++k) {
                a[j][k] -= ratio * a[i][k]; // Subtract the appropriate multiple
            }
        }
    }

    // Back Substitution Process
    // Solve for variables starting from the last row
    for (int i = n - 1; i >= 0; --i) {
        x[i] = a[i][n]; // Start with the constant (RHS)
        // Subtract the known values from already computed variables
        for (int j = i + 1; j < n; ++j) {
            x[i] -= a[i][j] * x[j];
        }
        x[i] /= a[i][i]; // Divide by the diagonal element to solve for x[i]
    }

    // Output the solution
    cout << "\nSolution:\n";
    cout << fixed << setprecision(6);
    for (int i = 0; i < n; ++i) {
        cout << "x" << i + 1 << " = " << x[i] << endl;
    }

    return 0;
}
