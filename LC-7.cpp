#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;

    int ans = 0, rem;
    while (n != 0)
    {
        rem = n % 10;         // Extract the last digit
        ans = ans * 10 + rem; // Shift digits in `ans` left and add the new digit
        n /= 10;              // Remove the last digit from `n`
    }

    cout << "Reversed number: " << ans << endl;
    return 0;
}
