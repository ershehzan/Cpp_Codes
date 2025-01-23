#include <iostream>
using namespace std;
int main()
{
    int n, ans = 0, rem, mul = 1;
    cout << "Enter a number: ";
    cin >> n;

    while (n)
    {

        rem = n % 2;
        rem = rem ^ 1;
        ans = ans + rem * mul;
        mul *= 2;
        n /= 2;
    }
    cout << ans;
    return 0;
}