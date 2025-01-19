#include <iostream>
using namespace std;
int main()
{
    int n, i, j;
    cout << "Enter the number : ";
    cin >> n;

    for (i = 1; i <= n; i++)
    {
    //space print
        for (j = 1; j <= n-i; j++)
        {
            cout << " ";
        }
        for (j = i; j >= 1; j--)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}
/* Output

    1 
   2 1 
  3 2 1 
 4 3 2 1 
5 4 3 2 1 
   */