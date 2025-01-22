#include <iostream>
using namespace std;
int main()
{

    int n, sum = 0;
    cout << "Enter a num :";
    cin >> n;
    int i = 1; // Initialize
    do
    {
        sum = sum + i;
        cout << sum << endl;
        i++;

    } while (i <= n);

    return 0;
}