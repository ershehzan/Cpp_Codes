#include <iostream>
using namespace std;
int main()
{
    int n, i, j;
    cout << "Enter the number : ";
    cin >> n;

    for (i = 1; i <= n; i++)
    {
// Loop run from 1 to no. of rows 1 to j = row
        for (j = 1; j <= i; j++)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}
/* Output
1       
2 2     
3 3 3   
4 4 4 4 
5 5 5 5 5    */