#include <iostream>
using namespace std;

int sum(int a, int b)
{

    int result = a + b;
    return result;
}
int main()
{
    int x, y;
    cout << "Enter the numbers :" ;
    cin >> x >> y;
    cout << "The sum of the two numbers is : " << sum(x, y) << endl;

    return 0;
}
