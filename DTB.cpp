// Decimal to binary
#include <iostream>
using namespace std;
int main()
{
    int n;
    int rem, ans = 0, mul = 1;

    cout << "Enter a Decimal Number : ";
    cin >> n;
    while (n > 0)
    {
        // remainder
        rem = n % 2;
        // Qoutient
        n /= 2;
        // answer
        ans += rem * mul;
        // multiple
        mul *= 10;
    }
    cout << "Binary Number is : " << ans;
    return 0;
}