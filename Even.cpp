#include <iostream>
using namespace std;

// A recursive function to print all even numbers from 2 to n
void even(int n)
{
    // Base case: If n is 2, print it and return
    if (n == 2)
    {
        cout << 2 << " ";
        return;
    }
    // Recursive call: Print even numbers up to n-2
    even(n - 2);

    // Print the current even number
    cout << n << " ";
}

int main()
{
    int n;

    // Prompt the user to enter a number
    cout << "Enter a number: ";
    cin >> n;

    // Inform the user what the program will do
    cout << "Even numbers from 1 to " << n << ": ";

    // Call the recursive function to print even numbers
    even(n);

    // End the program
    return 0;
}
