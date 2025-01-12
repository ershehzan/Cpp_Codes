// Sum from 1 to n using loop
#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter a number : ";
    cin >> n;
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += i;
    }
    cout << "Sum from 1 to " << n << " is " << sum;

    return 0;
}