#include <iostream>
using namespace std;
int main()
{
 
    int n, row, col;
    cout << "Enter a number :";
    cin >> n;
    for (row = 1; row <= n; row++)
    {
        // Nested loop
        for ( col = 1;  col <= n;  col++)
        {
            cout <<  col << " ";
        }
        cout << endl;
    }

    return 0;
}
/*Output
1 2 3 4 5 
1 2 3 4 5 
1 2 3 4 5 
1 2 3 4 5 
1 2 3 4 5  */
