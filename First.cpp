#include <iostream>
using namespace std;

void funcR(int n)
{
    if (n == 0)
    {
        cout << "Happy Birthday:\n";
        return;
    }
    cout << n << " Days left for Birthday" << endl;
    funcR(n - 1);
}

int main()
{

    funcR(5);

    return 0;
}