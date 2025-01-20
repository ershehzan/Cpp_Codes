#include <iostream>
using namespace std;
int main()
{
    int n, i, j;
    cout << "Enter the number : ";
    cin >> n;

    for (i = 1; i <= n; i++)
    {
        // space print
        for (j = 1; j <= n - i; j++)
        {
            cout << "  ";
        }

        for (j = 1; j <= i; j++)
        {
            char name = 'A' + j - 1; 

            cout << name << " ";
        }
        cout << endl;
    }
    return 0;
}
/* Output

        A 
      A B 
    A B C 
  A B C D 
A B C D E
   */