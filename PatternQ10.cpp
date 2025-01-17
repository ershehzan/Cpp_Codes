#include <iostream>
using namespace std;
int main()
{
    int n, i, j;
    cout << "Enter the number : ";
    cin >> n;

    for (i = 1; i <= n; i++)
    {
// Loop run from 1 to no. of rows 
        for (j = 1; j <= i; j++)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}
/* Output
1         
1 2       
1 2 3     
1 2 3 4   
1 2 3 4 5    */