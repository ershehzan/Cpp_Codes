#include <iostream>
using namespace std;
int main()
{
    int num;
    cin >> num;
    int row, col;
    for (row = 1; row <= num; row++)
    {
        for (col = 1; col <= num; col++)
        {
            cout << col * col << " ";
        }
        cout << endl;
    }
}
