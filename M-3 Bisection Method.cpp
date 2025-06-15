#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double f(double x) {
    return 2 * pow(x, 3) + 3 * x - 1;
}

int main() {
    double x1, x2, x0, f1, f2, f0, epsilon=1e-6;
    int iteration = 1;


    cout << "Enter the value of x1: ";
    cin >> x1;
    cout << "Enter the value of x2: ";
    cin >> x2;
   

    f1 = f(x1);
    f2 = f(x2);

    // Check if initial interval brackets a root
    if (f1 * f2 > 0) {
        cout << "\nThe function has the same sign at both endpoints.\n";
        cout << "Please choose a different interval where f(x1) * f(x2) < 0.\n";
        return 1;
    }

    cout << "\n-------------------------------------------------------------\n";
    cout << " Iteration    x1         x2         x0         f(x0)\n";
    cout << "-------------------------------------------------------------\n";

    do {
        x0 = (x1 + x2) / 2;
        f0 = f(x0);

        cout << fixed << setprecision(6);
        cout << setw(5) << iteration << "    "
             << setw(9) << x1 << "  "
             << setw(9) << x2 << "  "
             << setw(9) << x0 << "  "
             << setw(9) << f0 << "\n";

        // Update interval
        if (f1 * f0 < 0) {
            x2 = x0;
            f2 = f0;
        } else {
            x1 = x0;
            f1 = f0;
        }

        iteration++;
    } while (fabs((x2 - x1) / x2) >= epsilon);

    x0 = (x1 + x2) / 2;
    cout << "\nApproximate root = " << x0 << endl;

    return 0;
}
