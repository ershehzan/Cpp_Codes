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
        // star print
        for (j = 1; j <= i; j++)
        {

            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}
/* Output

        1 
      1 2 
    1 2 3 
  1 2 3 4 
1 2 3 4 5 
   */