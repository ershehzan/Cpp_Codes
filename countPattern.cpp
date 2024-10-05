#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int row, col,count=1;
    for (row = 1; row <= n; row++)
    {
        for (col = 1; col <= n; col++)
        {
            cout << count << " ";
            count++;
        }
        cout << endl;
    }
}