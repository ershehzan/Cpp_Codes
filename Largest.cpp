#include <iostream> 
using namespace std; 

int main()
{
    int a, b, c; // Declare three integer variables to store input values

    // Prompt the user to enter values for a, b, and c
    cout << "Enter the value of a, b and c: ";
    cin >> a >> b >> c; // Read input values from the user

    // Check which number is the greatest using conditional statements
    if (a > b && a > c) // If 'a' is greater than both 'b' and 'c'
    {
        cout << "a is greater than b and c";
    }
    else if (b > a && b > c) // If 'b' is greater than both 'a' and 'c'
    {
        cout << "b is greater than a and c";
    }
    else // If neither 'a' nor 'b' is the greatest, then 'c' must be the greatest
    {
        cout << "c is greater than a and b";
    }

    return 0; 
}
