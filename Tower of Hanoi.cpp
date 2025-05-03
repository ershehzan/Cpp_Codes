
#include <iostream>
using namespace std;

void toh(int n, int sou, int help, int des)
{
    if (n == 1)
    {
        cout << "Move disk 1 from rod " << sou << " to rod " << des << endl;
        return;
    }

    toh(n - 1, sou, des, help);
    cout << "Move disk " << n << " from rod " << sou << " to rod " << des << endl;
    toh(n - 1, help, sou, des);
}
int main()
{

    int n;
    cout << "Enter the number of disks: ";
    cin >> n;
    cout << "The sequence of moves involved in the Tower of Hanoi are :\n";

    int sou = 1, help = 2, des = 3; // Define and initialize the rods
    toh(n, sou, help, des); // Call the function without cout
}