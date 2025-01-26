// Decimal to binary
#include <iostream>
using namespace std;
int main()
{
    int num;
    int rem, ans = 0, mul = 1;

    cout << "Enter a Decimal Number : ";
    cin >> num;
    while (num > 0)
    {
        // remainder
        rem = num % 2;
        // Qoutient
        num /= 2;
        // answer
        ans += rem * mul;
        // multiple
        mul *= 10;
    }
    cout << "Binary Number is : " << ans;
    return 0;
}
