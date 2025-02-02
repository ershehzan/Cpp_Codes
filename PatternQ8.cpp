#include <iostream>
using namespace std;
int main()
{
    // i=row    j=column
    int num;
    // Extra variable
     int count = 1;
    cout << "Enter a number : ";
    cin >> num;
    for (int i = 1; i <= num; i++)
    {
        for (int j = 1; j <= num; j++)
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
