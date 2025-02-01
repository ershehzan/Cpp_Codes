#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    // Row = i    Column = j
    int i, j;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            cout << j * j << " ";
        }
        cout << endl;
    }
}
