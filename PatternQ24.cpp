#include <iostream>
using namespace std;
int main()
{
    // i=row   j= column
    int n, i, j;
    cout << "Enter the number : ";
    cin >> n;

    for (i = 1; i <= n; i++)
    {
        // space print
        for (j = 1; j <= n - i; j++)

            cout << "  ";
        // number print
        for (j = 1; j <= i; j++)
        {

            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}
/* Output

        1 
      2 2 
    3 3 3 
  4 4 4 4 
5 5 5 5 5 
   */