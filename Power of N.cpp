#include <iostream>
using namespace std;

int pow(int num,int n)
{

    if (n == 0)
    {
        return 1;
    }

    return num * pow(num,n - 1);
};

int main()
{
    int num;
    cout << "Enter a the number: ";
    cin >> num;

    int n;
    cout << "Enter a the power: ";
    cin >> n;
    if (n < 0)
    {
        cout << "Power of negative number doesn't exist" << endl;
        return 0;
    }
    cout << "Power of " <<num<<"^"<< n << " is: " << pow(num,n) << endl;
    return 0;
}