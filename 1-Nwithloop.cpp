// Sum from 1 to n using loop
#include <iostream>
using namespace std;
int main()
{
    int num;
    cout << "Enter a number : ";
    cin >> num;
    int sum = 0;
    for (int i = 1; i <= num; i++)
    {
        sum += i;
    }
    cout << "Sum from 1 to " << num << " is " << sum;

    return 0;
}
