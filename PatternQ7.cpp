#include <iostream>
using namespace std;
int main()
{
    // i=row    j=column
    int n, i, j;

    cout << "Enter a number :";
    cin >> n;
    for (i = 1; i <= n; i++)
    {
      
        // Nested loop
        for (j = 1; j <= n; j++)
        {
              char name = 'a' + j - 1;
            cout << name << "  ";
        }
        cout << endl;
    }

    return 0;
}
/* Output
a  b  c  d  e        
a  b  c  d  e        
a  b  c  d  e        
a  b  c  d  e        
a  b  c  d  e   */