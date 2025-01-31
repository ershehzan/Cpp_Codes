// Prime Number
#include <iostream>
using namespace std;

int main()
{
    int num;
    cout << "Enter a number: ";
    cin >> num;

    if (num < 2)
    {
        cout << "Number is not prime";
        return 0;
    }

    for (int i = 2; i <= num/2; i++) 
    {
        if (num % i == 0)
        {
            cout << "Number is not prime";
            return 0;
        }
    }

    cout << "Number is prime";
    return 0;
}
