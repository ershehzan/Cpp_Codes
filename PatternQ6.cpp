#include <iostream>
using namespace std;
int main()
{
    // i=row    j=column
    int num;

    cout << "Enter a number :";
    cin >> num;
    for (int i = 1; i <= num; i++)
    {
        char name = 'a' + (i - 1);
        // Nested loop
        for (int j = 1; j <= num; j++)
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
