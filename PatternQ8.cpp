#include <iostream>
using namespace std;
int main()
{
    // i=row    j=column
    int n, i, j;
    // Extra variable
     int count = 1;
    cout << "Enter a number : ";
    cin >> n;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
           // cout << (i - 1) * 5 + j << " "; //Alternate solution
            cout << count << " ";
            count++;
        }
        cout << endl;
    }

    return 0;
}
/* Output
1 2 3 4 5
6 7 8 9 10
11 12 13 14 15
16 17 18 19 20
21 22 23 24 25   */
