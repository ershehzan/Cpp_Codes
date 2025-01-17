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
        char name = 'a' + (i - 1);
        // Nested loop
        for (j = 1; j <= n; j++)
        {
            cout << name << "  ";
        }
        cout << endl;
    }

    return 0;
}
/* Output
a  a  a  a  a        
b  b  b  b  b        
c  c  c  c  c        
d  d  d  d  d        
e  e  e  e  e  */