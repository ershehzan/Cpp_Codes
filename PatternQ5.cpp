#include <iostream>
using namespace std;
int main()
{
    // i=row    j=column
    int n;
    cout << "Enter a number :";
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        // Nested loop
        for (int j = 1; j <= n; j++)
        {
            cout << " * ";
        }
        cout << endl;
    }

    return 0;
}
/*Output
5 4 3 2 1 
5 4 3 2 1 
5 4 3 2 1 
5 4 3 2 1 
5 4 3 2 1  */
