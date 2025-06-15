#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double f(double x) 
{
    return pow(x, 3) - 4;
}

int main() {
    double x1, x2, x0, f1, f2, f0;
    int maxIterations;
    cout << "Enter the initial value of x1: ";
    cin >> x1;
    cout << "Enter the initial value of x2: ";
    cin >> x2;
    cout << "Enter the number of iterations to perform: ";
    cin >> maxIterations;
 
    f1 = f(x1);
    f2 = f(x2);

    if (f1 * f2 > 0) {
        cout << "\nInvalid interval. f(x1) and f(x2) have the same signs." << endl;
        cout << "No root is guaranteed between x1 and x2.\n";
        return 1;
    }

    cout << fixed << setprecision(6);
    cout << "\n---------------------------------------------------------------\n";
    cout << " Iteration     x1         x2         x0       f(x0)\n";
    cout << "---------------------------------------------------------------\n";

    for (int i = 1; i <= maxIterations; ++i) {
        x0 = x1 - (f1 * (x2 - x1)) / (f2 - f1);
        f0 = f(x0);
        cout << setw(5) << i << "     "
             << setw(9) << x1 << "  "
             << setw(9) << x2 << "  "
             << setw(9) << x0 << "  "
             << setw(9) << f0 << "\n";
        if (f1 * f0 < 0) {
            x2 = x0;
            f2 = f0;
        } else {
            x1 = x0;
            f1 = f0;
        }
    }

    cout << "\nApproximate root after " << maxIterations << " iterations: " << x0 << endl;
    return 0;
}
