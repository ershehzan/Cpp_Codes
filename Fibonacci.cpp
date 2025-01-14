// Fibonacci series
#include <iostream>
using namespace std;

int main()
{
    int n, last = 0, cur = 1, next;
    cout << "Enter the number of terms for the Fibonacci series:: ";
    cin >> n;
    for (int i = 1; i <= n; i++)
    {

        cout << last << " ";
        next = last + cur;
        last = cur;
        cur = next;
    }

    return 0;
}
