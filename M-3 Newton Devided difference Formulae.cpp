#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;
void displayDividedDifferenceTable(const vector<vector<double>>& table, int n) {
    cout << "\nDivided Difference Table:\n";
    for (int i = 0; i < n; ++i) {
        cout << setw(10) << "x[" << i << "] = " << table[i][0] << " | ";
        for (int j = 1; j <= i; ++j) {
            cout << setw(10) << table[i][j] << " ";
        }
        cout << endl;
    }
}
double newtonDividedDifference(vector<double>& x, vector<double>& y, double value) {
    int n = x.size();
    vector<vector<double>> table(n, vector<double>(n));
    for (int i = 0; i < n; ++i) {
        table[i][0] = y[i];
    }
    for (int j = 1; j < n; ++j) {
        for (int i = j; i < n; ++i) {
            table[i][j] = (table[i][j - 1] - table[i - 1][j - 1]) / (x[i] - x[i - j]);
        }
    }
    displayDividedDifferenceTable(table, n);
    double result = table[0][0];
    double term = 1.0;
    for (int i = 1; i < n; ++i) {
        term *= (value - x[i - 1]);
        result += term * table[i][i];
    }
    return result;
}
int main() {
    int n;
    cout << "Enter the number of data points: ";
    cin >> n;
    vector<double> x(n), y(n);
    cout << "Enter the x values:\n";
    for (int i = 0; i < n; ++i) {
        cout << "x[" << i << "]: ";
        cin >> x[i];
    }
    cout << "Enter the corresponding y values:\n";
    for (int i = 0; i < n; ++i) {
        cout << "y[" << i << "]: ";
        cin >> y[i];
    }
    double value;
    cout << "Enter the value of x for which you want to interpolate f(x): ";
    cin >> value;
    double result = newtonDividedDifference(x, y, value);
    cout << fixed << setprecision(6);
    cout << "\nInterpolated value at x = " << value << " is f(x) = " << result << endl;
    return 0;
}
