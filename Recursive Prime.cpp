#include <iostream>
using namespace std;

bool isPrimeRecursive(int n, int i = 2)
{
    if (n <= 1)
        return false;
    if (i == n)
        return true;
    if (n % i == 0)
        return false;

    return isPrimeRecursive(n, i + 1);
}

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;

    if (isPrimeRecursive(n))
        cout << n << " is a prime number." << endl;
    else
        cout << n << " is not a prime number." << endl;

    return 0;
}
