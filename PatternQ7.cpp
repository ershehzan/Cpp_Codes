#include <iostream>
using namespace std;
int main()
{
    // i=row    j=column
    int num;

    cout << "Enter a number :";
    cin >> numn;
    for (int i = 1; i <= num; i++)
    {
      
        // Nested loop
        for (int j = 1; j <= num; j++)
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
