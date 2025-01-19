#include <iostream>
using namespace std;
int main()
{
    int n, i, j;
    cout << "Enter the number : ";
    cin >> n;

    for (i = 1; i <= n; i++)
    {
        
        for (j = n; j >= n - i + 1; j--)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}
/* Output
5 
5 4 
5 4 3 
5 4 3 2 
5 4 3 2 1    */