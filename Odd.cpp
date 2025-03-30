#include <iostream>
using namespace std;
int main()
{

    int n;
    cout << "Enter a number :";
    cin >> n;
    int i = 1;     // Initialize
    while (i <= n) // Break
    {

        if (i % 2 == !0)
        {
            cout << i << " ";
        }
        i++; // Update
    }
    return 0;
}
