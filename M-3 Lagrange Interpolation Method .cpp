#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    double x;

    cout << "Enter the number of data points: ";
    cin >> n;

    vector<double> xi(n), fi(n);

    cout << "Enter the data points (xi and f(xi)):\n";
    for (int i = 0; i < n; i++) {
        cout << "x[" << i << "]: ";
        cin >> xi[i];
        cout << "f(x[" << i << "]): ";
        cin >> fi[i];
    }

    cout << "\nEnter the value of x to interpolate f(x): ";
    cin >> x;

    double fx = 0;

    for (int i = 0; i < n; i++) {
        double term = fi[i];
        for (int j = 0; j < n; j++) {
            if (j != i) {
                term *= (x - xi[j]) / (xi[i] - xi[j]);
            }
        }
        fx += term;
    }

    cout << "\nInterpolated value at x = " << x << " is f(x) = " << fx << endl;

    return 0;
}
