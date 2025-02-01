#include <iostream>
using namespace std;
int main()
{
  
    int num,row,col;
    cout << "Enter a number :";
    cin >> num;
    for (row = 1; row <= n; row++)
    {
        // Nested loop
        for (col = 1; col <= n; col++)
        {
            cout << col * col << "  ";
        }
        cout << endl;
    }

    return 0;
}
/* Output
1  4  9  16  25      
1  4  9  16  25      
1  4  9  16  25      
1  4  9  16  25      
1  4  9  16  25 */
