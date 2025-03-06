#include <iostream>
using namespace std;

int add(int a, int b)
{
    return a + b;
}

double add(double a, double b)
{
    return a + b;
}

int main()
{
    cout<<"Function overloading: "<<endl;
    cout<<"Integer addition: ";
    cout << add(1, 2) << endl;
    cout<<"Double addition: ";
    cout << add(1.1, 2.2) << endl;
}