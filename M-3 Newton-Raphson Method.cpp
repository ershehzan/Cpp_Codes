#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

// Function to evaluate f(x) = x^3 - 4x - 9
double f(double x) {
    return pow(x, 3) - 4 * x - 9;
}

// Function to evaluate derivative f'(x) = 3x^2 - 4
double f_prime(double x) {
    return 3 * pow(x, 2) - 4;
}

int main() {
    double x0, x1, epsilon=1e-6; // x0: initial guess, x1: next guess, epsilon: tolerance for stopping
    int iteration = 0;           // To count number of iterations

    // Prompt user for initial guess
    cout << "Enter initial guess (x0): ";
    cin >> x0;
   
    // Set formatting for floating point output
    cout << fixed << setprecision(6);
    cout << "\n---------------------------------------------------------\n";
    cout << " Iteration      x0          f(x0)       f'(x0)       x1\n";
    cout << "---------------------------------------------------------\n";

    // Begin Newton-Raphson iteration
    while (true) {
        double fx = f(x0);         // f(x0)
        double fpx = f_prime(x0);  // f'(x0)

        // Check if derivative is zero to avoid division by zero
        if (fpx == 0) {
            cout << "\nMath error: Derivative is zero. Cannot continue.\n";
            return 1; // Exit with error
        }

        // Compute the next approximation (Newton-Raphson formula)
        x1 = x0 - fx / fpx;

        // Print current iteration's values
        cout << setw(5) << ++iteration << "      "
             << setw(9) << x0 << "   "
             << setw(9) << fx << "   "
             << setw(9) << fpx << "   "
             << setw(9) << x1 << "\n";

        // Stopping condition: check if the relative error is within tolerance
        if (fabs((x1 - x0) / x1) < epsilon)
            break;

        // Prepare for next iteration
        x0 = x1;
    }

    // Output the approximated root
    cout << "\nApproximate root = " << x1 << " after " << iteration << " iterations.\n";
    return 0;
}
