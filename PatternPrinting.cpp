#include <iostream>
using namespace std;
int main()
{
    int num;
    cin >> num;
    // Row = i    Column = j
    int i, j;
    for (i = 1; i <= num; i++)
    {
        for (j = 1; j <= num; j++)
        {
            cout << j * j << " ";
        }
        cout << endl;
    }
}
