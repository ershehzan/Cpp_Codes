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

            cout << " ";
        // star print
        for (j = 1; j <= 2 * i - 1; j++)
        {

            cout << "*";
        }
        cout << endl;
    }
    return 0;
}
/* Output

    *
   ***
  *****
 *******
*********

   */