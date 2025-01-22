// binary to decimal
#include <iostream>
using namespace std;
int main()
{
    int n;
    int rem, ans = 0, mul = 1;
    cout << "Enter a binary number : ";
    cin >> n;
    while (n > 0)
    {
        // remainder
        rem = n % 10;
        // qoutient
        n /= 10;
        // answer
        ans += rem * mul;
        // multiple
        mul *= 2;
    }
    cout << "Decimal number is : " << ans;
    return 0;
}