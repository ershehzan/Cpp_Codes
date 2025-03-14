#include <iostream>
using namespace std;

int main()
{

    int arr[4][4] = {{1, 2, 3, 4},
                     {19, 5, 6, 72},
                     {6, 8, 9, 10},
                     {15, 12, 13, 14}};
    int first = 0, second = 0;

    for (int i = 0; i < 4; i++)
    {
        first += arr[i][i];
        second += arr[i][4 - i - 1];
    }
    // int i = 0, j = 3;
    // while (j >= 0)
    // {
    //     second += arr[i][j];
    //     i++;
    //     j--;
    // }
    cout << "Sum of first diagonal: " << first << endl;
    cout << "Sum of second diagonal: " << second << endl;
    return 0;
}
