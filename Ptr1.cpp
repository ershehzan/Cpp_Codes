#include <iostream>
using namespace std;
int main()
{

    int a = 10;
    int *p = &a;

    cout << "Value of a: " << a << endl;    // Output: 10
    cout << "Address of a: " << &a << endl; // Output: Address of a

    cout << "Value of a using pointer p: " << *p << endl; // Output: 10
    cout << "Address of a using pointer p: " << p << endl; // Output: Address of a

    return 0;
}