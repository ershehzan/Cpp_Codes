#include <iostream>
using namespace std;
int main()
{
   
    int n, row, col;
    cout << "Enter a number :";
    cin >> n;
    for (row = 1; row<= n; row++)
    {
        // Nested loop
        for ( col = 1;  col <= n;  col++)
        {

            cout << row << " ";
        }
        cout << endl;
    }

    return 0;
}
/* output
1 1 1 1 1 
2 2 2 2 2 
3 3 3 3 3 
4 4 4 4 4 
5 5 5 5 5 */
