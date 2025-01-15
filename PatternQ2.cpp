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

            cout << i << " ";
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