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
            cout << "  ";
        }
        char name ='A'+(i-1);//if we take j instead of i then o/p will be opposite
        for (j = 1; j <= i; j++)
        {
            cout << name << " ";
        }
        cout << endl;
    }
    return 0;
}
/* Output

        A 
      B B 
    C C C 
  D D D D 
E E E E E
   */