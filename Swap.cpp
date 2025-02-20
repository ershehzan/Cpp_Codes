#include <iostream>
using namespace std;

// Function to swap two numbers using pass by reference
void swap(int &a, int &b) 
{
    int c; // Temporary variable to store the value of 'a'
    c = a;
    a = b;
    b = c;
}

int main()
{
    int x, y;
    
    // Prompting the user to enter values for x and y
    cout << "Enter the value of a and b : ";
    cin >> x >> y; // Taking input from the user

    // Calling the swap function to interchange the values of x and y
    swap(x, y);

    // Displaying the swapped values
    cout << x << " " << y;
    
    return 0;
}
