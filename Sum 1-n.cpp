
#include <iostream>
using namespace std;

int print(int n)
{
    if (n == 0)

        return 0;
    return n + print(n - 1);
};

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;

    int result = print(n);
    cout << "The sum of numbers from 1 to " << n << " is: " << result << endl;

    return 0;
}