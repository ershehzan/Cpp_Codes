// factorial
#include <iostream>
using namespace std;
int main()
{
    int num;
    cout << "Enter a number : ";
    cin >> num;
    double fact = 1;
    for (int i = 1; i <= num; i++)
    {
        fact *= i;
    }
    cout << "Factorial of " << num << " is " << fact;

    return 0;
}
