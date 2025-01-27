// Binary to Decimal
#include <iostream>
using namespace std;
int main()
{
    int num;
    int rem, ans = 0, mul = 1;
    cout << "Enter a Binary number : ";
    cin >> num;
    while (num> 0)
    {
        // remainder
        rem = num % 10;
        // qoutient
        num /= 10;
        // answer
        ans += rem * mul;
        // multiple
        mul *= 2;
    }
    cout << "Decimal number is : " << ans;
    return 0;
}
