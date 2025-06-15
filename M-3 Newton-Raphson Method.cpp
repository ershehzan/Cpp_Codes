#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;


double f(double x) {
    return pow(x, 3) - 4 * x - 9;
}

double f_prime(double x) {
    return 3 * pow(x, 2) - 4;
}

int main() {
    double x0, x1, epsilon=1e-6;
    int iteration = 0;


    cout << "Enter initial guess (x0): ";
    cin >> x0;
   

    cout << fixed << setprecision(6);
    cout << "\n---------------------------------------------------------\n";
    cout << " Iteration      x0          f(x0)       f'(x0)       x1\n";
    cout << "---------------------------------------------------------\n";

    while (true) {
        double fx = f(x0);
        double fpx = f_prime(x0);

   
        if (fpx == 0) {
            cout << "\nMath error: Derivative is zero. Cannot continue.\n";
            return 1;
        }

        x1 = x0 - fx / fpx;


        cout << setw(5) << ++iteration << "      "
             << setw(9) << x0 << "   "
             << setw(9) << fx << "   "
             << setw(9) << fpx << "   "
             << setw(9) << x1 << "\n";

        if (fabs((x1 - x0) / x1) < epsilon)
            break;

        x0 = x1;
    }

    cout << "\nApproximate root = " << x1 << " after " << iteration << " iterations.\n";
    return 0;
}
