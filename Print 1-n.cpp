#include <iostream>
using namespace std;

// A recursive function to print numbers from 1 to n
void print(int n)
{
    // Base case: If n is 1, print it and return
    if (n == 1)
    {
        cout << n << endl;
        return;
    }

    // Recursive call: Print numbers from 1 to n-1
    print(n - 1);

    // Print the current number after the recursive call
    cout << n << endl;
}

int main()
{
    int n;

    // Prompt the user to enter a number
    cout << "Enter a number: ";
    cin >> n;

    // Call the recursive function to print numbers from 1 to n
    print(n);

    // End the program
    return 0;
}
