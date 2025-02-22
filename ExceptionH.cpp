#include <iostream>
using namespace std;

int divide(int a, int b)
{
    // Check for division by zero
    if (b == 0)
    {
        throw runtime_error("Division by zero is not allowed."); // Throw an exception
    }
    return a / b;
}

int main()
{
    int num1, num2;

    // Taking input from the user
    cout << "Enter two numbers (numerator and denominator): ";
    cin >> num1 >> num2;

    try
    {
        // Attempt to divide the numbers
        int result = divide(num1, num2);
        cout << "Result: " << result << endl;
    }
    catch (const runtime_error &e) // Catching the exception
    {
        // Display the error message
        cout << "Error: " << e.what() << endl;
    }

    cout << "Program continues after exception handling." << endl;

    return 0;
}
