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
        // 1 to n
        for (j = 1; j <= i; j++)

            cout << j << " ";
        // n to 1
        for (j = i - 1; j >= 1; j--)

            cout << j << " ";

        cout << endl;
    }
    return 0;
}
/* Output

        1 
      1 2 1 
    1 2 3 2 1        
  1 2 3 4 3 2 1      
1 2 3 4 5 4 3 2 1 

   */