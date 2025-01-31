#include <iostream>
using namespace std;

bool prime(int num)
{
    if (num == 2)
        return 0;
    for (int i = 2; i < num; i++)
    {
        if (num % i == 0)
            return 0;
    }
    return 1;
}

int fact(int num)
{

    double fact = 1;
    for (int i = 1; i <= num; i++)
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
