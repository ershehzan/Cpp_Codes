#include <iostream>
#include <iomanip>      // For setting output precision and formatting
#include <vector>       // For using vector container

using namespace std;

// Function to display the divided difference table
void displayDividedDifferenceTable(const vector<vector<double>>& table, int n) {
    cout << "\nDivided Difference Table:\n";
    for (int i = 0; i < n; ++i) {
        // Display x values for clarity
        cout << setw(10) << "x[" << i << "] = " << table[i][0] << " | ";
        // Display the divided differences for each order
        for (int j = 1; j <= i; ++j) {
            cout << setw(10) << table[i][j] << " ";
        }
        cout << endl;
    }
}

// Function to perform Newton's Divided Difference interpolation
// x: vector of x-values, y: vector of corresponding y-values, value: the interpolation point
double newtonDividedDifference(vector<double>& x, vector<double>& y, double value) {
    int n = x.size();

    // Create a table to store the divided differences
    vector<vector<double>> table(n, vector<double>(n));

    // Initialize the first column of the table with y values
    for (int i = 0; i < n; ++i) {
        table[i][0] = y[i];
    }

    // Calculate the divided differences for higher orders
    for (int j = 1; j < n; ++j) {
        for (int i = j; i < n; ++i) {
            // Formula: f[x_i, ..., x_{i-j}] = (f[x_i, ..., x_{i-j+1}] - f[x_{i-1}, ..., x_{i-j}]) / (x[i] - x[i-j])
            table[i][j] = (table[i][j - 1] - table[i - 1][j - 1]) / (x[i] - x[i - j]);
        }
    }

    // Display the divided difference table for reference
    displayDividedDifferenceTable(table, n);

    // Apply Newton's Divided Difference formula to interpolate the value
    double result = table[0][0]; // Start with f[x0]
    double term = 1.0;

    // Loop to calculate each term of the Newton interpolating polynomial
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

    // Input x values
    cout << "Enter the x values:\n";
    for (int i = 0; i < n; ++i) {
        cout << "x[" << i << "]: ";
        cin >> x[i];
    }

    // Input corresponding y values
    cout << "Enter the corresponding y values:\n";
    for (int i = 0; i < n; ++i) {
        cout << "y[" << i << "]: ";
        cin >> y[i];
    }

    // Input the x value for which to interpolate f(x)
    double value;
    cout << "Enter the value of x for which you want to interpolate f(x): ";
    cin >> value;

    // Calculate the interpolated value using Newton's Divided Difference
    double result = newtonDividedDifference(x, y, value);

    // Set output format to fixed with 6 decimal places
    cout << fixed << setprecision(6);

    // Output the interpolated value
    cout << "\nInterpolated value at x = " << value << " is f(x) = " << result << endl;

    return 0;
}
