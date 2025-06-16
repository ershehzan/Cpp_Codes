#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;         // Number of data points
    double x;      // The value at which interpolation is to be done

    // Prompt the user to enter the number of data points
    cout << "Enter the number of data points: ";
    cin >> n;

    // Vectors to store x coordinates (xi) and corresponding f(xi) values
    vector<double> xi(n), fi(n);

    // Input the data points from the user
    cout << "Enter the data points (xi and f(xi)):\n";
    for (int i = 0; i < n; i++) {
        cout << "x[" << i << "]: ";
        cin >> xi[i];                // x-coordinate
        cout << "f(x[" << i << "]): ";
        cin >> fi[i];                // Function value at x-coordinate
    }

    // Prompt the user for the interpolation point
    cout << "\nEnter the value of x to interpolate f(x): ";
    cin >> x;

    double fx = 0;   // This will store the final interpolated value

    // Lagrange Interpolation Formula
    for (int i = 0; i < n; i++) {
        double term = fi[i]; // Start with f(xi) for this term

        // Compute the Lagrange basis polynomial for index i
        for (int j = 0; j < n; j++) {
            if (j != i) {
                // Multiply by (x - xj) / (xi - xj) for each j != i
                term *= (x - xi[j]) / (xi[i] - xi[j]);
            }
        }
        fx += term; // Add this term to the result
    }

    // Output the interpolated value at the given x
    cout << "\nInterpolated value at x = " << x << " is f(x) = " << fx << endl;

    return 0;
}
