#include <iostream>
using namespace std;

void even(int n)
{

    if (n == 2)
    {
        cout << 2 << " ";
        return;
    }
    even(n - 2);
    cout << n << " ";
}

int main()
{
    int n;

    cout << "Enter a number: ";
    cin >> n;
    cout<<"Even numbers from 1 to "<<n<<": ";
    even(n);
    return 0;
}