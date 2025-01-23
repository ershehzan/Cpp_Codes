#include <iostream>
using namespace std;

// void swap(int a, int b) // pass by value

void swap(int &a, int &b) // pass by reference
{

    int c;
    c = a;
    a = b;
    b = c;
}

int main()
{
    int x, y;
    cout << "Enter the value of a and b : ";
    cin >> x >> y;
    swap(x, y);
    cout << x << " " << y;
    return 0;
}
