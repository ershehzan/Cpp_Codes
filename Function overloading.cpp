#include <iostream>
using namespace std;

// Function overloading example
// Two functions with the same name but different parameter types.

// Function to add two integers
int add(int a, int b)
{
    return a + b; // Returns the sum of two integers
}

// Function to add two doubles
// Overloaded function with different parameter type
double add(double a, double b)
{
    return a + b; // Returns the sum of two doubles
}

int main()
{
    cout << "Function overloading: " << endl;
    
    // Calling the integer addition function
    cout << "Integer addition: ";
    cout << add(1, 2) << endl; // Calls the int version of add()
    
    // Calling the double addition function
    cout << "Double addition: ";
    cout << add(1.1, 2.2) << endl; // Calls the double version of add()
    
    return 0;
