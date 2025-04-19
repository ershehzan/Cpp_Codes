#include <iostream>
using namespace std;

int sumSqr(int n)
{
    if (n == 1)
    {
        return 1; // Base case: sum of squares of first 1 natural number is 1
    }
    return n * n + sumSqr(n - 1);
};
int main()
{

    int n;
    cout << "Enter a number: ";
    cin >> n;
    if (n < 0)
    {
        cout << "Please enter a non-negative integer." << endl;
        return 1; 
    }

    cout << "Sum of squares of first " << n << " natural numbers is: " << sumSqr(n) << endl;
}