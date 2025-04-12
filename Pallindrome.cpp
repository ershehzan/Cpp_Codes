#include <iostream>
using namespace std;
int main()
{
    int x, ans = 0, rem;
    cout << "Enter a number: ";
    cin >> x;
    int num = x;
    while (num != 0)
    {

        rem = num % 10;
        num /= 10;
        ans = ans * 10 + rem;
    }
    if (ans == x)
    {
        cout << "Number is pallindrome";
    }
    else
    {
        cout << "Number is not pallindrome";
    }

    return 0;
}
// LC- 9
//  if (x < 0)
//             return 0;

//         int n = x, rem, ans = 0;

//         while (n) {
//             rem = num % 10;

//             n /= 10;
//             if(ans>INT_MAX/10)
//             return 0;

//             ans = ans * 10 + rem;
//         }
//         if (ans == x)
//             return 1;
//         else
//             return 0;
//     
