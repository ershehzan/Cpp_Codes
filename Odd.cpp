#include <iostream>
using namespace std;
void odd(int n)
{

    if (n == 1)
    {

        cout << 1 << " ";
        return;
    }
    odd(n - 1);
    if (n % 2 != 0)
    {

        cout << n << " ";
    }
}

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;
    cout << "Odd numbers from 1 to " << n << ": ";
    odd(n);
    return 0;
}