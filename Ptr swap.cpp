#include <iostream> // Library for input and output operations
using namespace std;

// Function to swap the values of two integers using pointers
// This function demonstrates pass-by-pointer, allowing modification of the original variables
void swap(int *p1, int *p2)
{
    int temp = *p1; // Store the value of the first pointer in a temporary variable
    *p1 = *p2;      // Assign the value pointed by the second pointer to the first pointer
    *p2 = temp;     // Assign the stored value in temp to the second pointer
}

int main()
{
    int a = 10, b = 20; // Initialize two integer variables

    // Call the swap function, passing the addresses of variables a and b
    swap(&a, &b);

    // Print the swapped values of a and b
    cout << "a = " << a << endl; // After swapping, a = 20
    cout << "b = " << b << endl; // After swapping, b = 10

    return 0; // Indicate successful program termination
}
