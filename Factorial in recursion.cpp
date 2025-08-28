#include <iostream>
using namespace std;

int fact(int n){
    if (n == 0) {
        return 1;
    }
    return n * fact(n - 1);
}

int main()
{

    int n;
    cout << "Enter a number: ";
    cin >> n;
    if(n<0){
        cout<<"Factorial of negative number doesn't exist"<<endl;
        return 0;
    }

    cout << "Factorial of " << n << " is:" << fact(n);
    return 0;

}

