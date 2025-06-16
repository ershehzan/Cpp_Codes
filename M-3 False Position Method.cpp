#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

// Function definition for f(x) = x^3 - 4
double f(double x) 
{
    return pow(x, 3) - 4;
}

int main() {
    double x1, x2, x0, f1, f2, f0;
    int maxIterations;

    // Prompt user for the initial interval endpoints
    cout << "Enter the initial value of x1: ";
    cin >> x1;
    cout << "Enter the initial value of x2: ";
    cin >> x2;

    // Prompt user for the number of iterations to perform
    cout << "Enter the number of iterations to perform: ";
    cin >> maxIterations;
 
    // Calculate function values at the endpoints
    f1 = f(x1);
    f2 = f(x2);

    // Check if initial interval brackets a root (f(x1) and f(x2) should have opposite signs)
    if (f1 * f2 > 0) {
        cout << "\nInvalid interval. f(x1) and f(x2) have the same signs." << endl;
        cout << "No root is guaranteed between x1 and x2.\n";
        return 1; // Exit if not a valid interval
    }

    // Output table header for iterations
    cout << fixed << setprecision(6);
    cout << "\n---------------------------------------------------------------\n";
    cout << " Iteration     x1         x2         x0       f(x0)\n";
    cout << "---------------------------------------------------------------\n";

    // Perform the False Position (Regula Falsi) method for maxIterations times
    for (int i = 1; i <= maxIterations; ++i) {
        // Calculate x0 using the False Position formula
        x0 = x1 - (f1 * (x2 - x1)) / (f2 - f1);
        f0 = f(x0); // Evaluate function at x0

        // Print the current iteration's values
        cout << setw(5) << i << "     "
             << setw(9) << x1 << "  "
             << setw(9) << x2 << "  "
             << setw(9) << x0 << "  "
             << setw(9) << f0 << "\n";

        // Update the interval based on the sign of f(x0)
        if (f1 * f0 < 0) {
            // The root lies between x1 and x0
            x2 = x0;
            f2 = f0;
        } else {
            // The root lies between x0 and x2
            x1 = x0;
            f1 = f0;
        }
    }

    // Output the final approximation of the root after maxIterations
    cout << "\nApproximate root after " << maxIterations << " iterations: " << x0 << endl;
    return 0;
}
