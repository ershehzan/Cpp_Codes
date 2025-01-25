#include <iostream>
using namespace std;
int main()
{

    int num, sum = 0;
    cout << "Enter a Number :";
    cin >> num;
    int i = 1; // Initialize
    do
    {
        sum  += i;
        cout << sum << endl;
        i++;

    } while (i <= num);

    return 0;
}
