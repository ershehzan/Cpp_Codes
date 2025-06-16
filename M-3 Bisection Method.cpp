#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

// Function definition for f(x) = 2x^3 + 3x - 1
double f(double x) {
    return 2 * pow(x, 3) + 3 * x - 1;
}

int main() {
    double x1, x2, x0, f1, f2, f0, epsilon=1e-6;
    int iteration = 1;

    // Prompt user for interval endpoints x1 and x2
    cout << "Enter the value of x1: ";
    cin >> x1;
    cout << "Enter the value of x2: ";
    cin >> x2;
   
    // Calculate function values at the endpoints
    f1 = f(x1);
    f2 = f(x2);

    // Check if initial interval brackets a root (f(x1) and f(x2) should have opposite signs)
    if (f1 * f2 > 0) {
        cout << "\nThe function has the same sign at both endpoints.\n";
        cout << "Please choose a different interval where f(x1) * f(x2) < 0.\n";
        return 1; // Exit if not a valid interval
    }

    // Print table header for iterations
    cout << "\n-------------------------------------------------------------\n";
    cout << " Iteration    x1         x2         x0         f(x0)\n";
    cout << "-------------------------------------------------------------\n";

    // Start the bisection method iteration
    do {
        x0 = (x1 + x2) / 2; // Calculate midpoint of interval
        f0 = f(x0);         // Evaluate function at midpoint

        // Print current iteration's values
        cout << fixed << setprecision(6);
        cout << setw(5) << iteration << "    "
             << setw(9) << x1 << "  "
             << setw(9) << x2 << "  "
             << setw(9) << x0 << "  "
             << setw(9) << f0 << "\n";

        // Determine which subinterval to keep
        if (f1 * f0 < 0) {
            // Root lies between x1 and x0
            x2 = x0;
            f2 = f0;
        } else {
            // Root lies between x0 and x2
            x1 = x0;
            f1 = f0;
        }

        iteration++; // Increment iteration count
    } while (fabs((x2 - x1) / x2) >= epsilon); // Continue until error tolerance is met

    x0 = (x1 + x2) / 2; // Final approximation of the root
    cout << "\nApproximate root = " << x0 << endl;

    return 0;
}
