#include <iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int row, col;
    for (row = 1; row <= n; row++)
    {
        for (col = n; col >= 1; col--)
        {
            cout << col << " ";
        }cout << endl;
    }
    
}