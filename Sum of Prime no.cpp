#include <iostream>
using namespace std;

bool isPrime(int n)
{
    if (n < 2)
        return false;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;
    // Sum of prime numbers up to n
    int sum = 0;

    if (isPrime(n))
    {
        cout << "Number is prime" << endl;
    }
    else
    {
        cout << "Number is not prime" << endl;
    }
    for (int i = 2; i <= n; i++)
    {

        if (isPrime(i))
        {
            sum += i;
        }
    }

    cout << "Sum of prime numbers up to " << n << " is: " << sum << endl;
    return 0;
}
