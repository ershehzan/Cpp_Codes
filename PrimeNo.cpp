// Prime Number
#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;

    if (n < 2)
    {
        cout << "Number is not prime";
        return 0;
    }

    for (int i = 2; i <= n/2; i++) 
    {
        if (n % i == 0)
        {
            cout << "Number is not prime";
            return 0;
        }
    }

    cout << "Number is prime";
    return 0;
}
