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

    int *p1;
    int b = 20;
    p1 = &b; // Initialize p1 to point to b
    cout << "Value of b using pointer p1: " << *p1 << endl; // Output: 20
    cout << "Address of b using pointer p1: " << p1 << endl; // Output: Address of b

    return 0;
}
