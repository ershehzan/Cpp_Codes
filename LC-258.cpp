// Sum of digits
#include <iostream>
using namespace std;
int main()
{
    int num;

    cout << "Enter a number : ";
    cin >> num;
    // start
    while (num > 9)
    {
        int rem, ans = 0;
        while (num != 0)
        {
            // remainder
            rem = num % 10;
            // Qoutient
            num /= 10;
            // answer
            ans += rem;
        }
        num = ans;
    }
    // sum would be in single digit
    cout << num;
    // end here
    return 0;
}