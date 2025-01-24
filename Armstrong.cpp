#include <iostream>
#include <cmath>
using namespace std;

int countdigit(int num)
{
    int count = 0;
    while (num)
    {
        count++;
        num = num / 10;
    }
    return count;
}

bool armstrong(int num, int digit)
{
    int n = num, ans = 0, rem;
    while (n)
    {
        rem = n % 10; // Use 'n' instead of 'num' here
        n /= 10;
        ans = ans + pow(rem, digit);
    }
    return ans == num; // Compare with original 'num'
}

int main()
{
    int num;
    cout << "Enter a number: ";
    cin >> num;
    // Count digits
    int digit = countdigit(num);
    // Check Armstrong number
    if (armstrong(num, digit))
        cout << num << " is an Armstrong number." << endl;
    else
        cout << num << " is not an Armstrong number." << endl;
    return 0;
}
