#include <iostream>
using namespace std;
int main()
{
    int num, ans = 0, rem, mul = 1;
    cout << "Enter a number: ";
    cin >> num;

    while (num)
    {

        rem = num % 2;
        rem = rem ^ 1;
        ans += rem * mul;
        mul *= 2;
        num /= 2;
    }
    cout << ans;
    return 0;
}
