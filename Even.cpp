#include <iostream>
using namespace std;
int main()
{

    int num;
    cout << "Enter a number :";
    cin >> num;
    int i = 1;     // Initialize
    while (i <= num) // Break
    {

        if (i % 2 == 0)
        {
            cout << i << " ";
        }
        i++; // Update
    }
    return 0;
}
