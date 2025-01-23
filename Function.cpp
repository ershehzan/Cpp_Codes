#include <iostream>
using namespace std;

bool prime(int n)
{
    if (n == 2)
        return 0;
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
            return 0;
    }
    return 1;
}

int fact(int n)
{

    double fact = 1;
    for (int i = 1; i <= n; i++)
    {
        fact *= i;
    }
    return fact;
}
int main()
{
    int a, b;
    cout << "Enter the first number: ";
    cin >> a;
    cout << "Enter the second number: ";
    cin >> b;
    cout << "Prime of a is : " << prime(a) << endl;
    cout << "Factorial of b is : " << fact(b) << endl;
    cout << "Prime of b-a is : " << prime(b - a) << endl;
    cout << "Factorial of b-a is : " << fact(b - a) << endl;
    return 0;
}