#include <iostream>
using namespace std;

int main()
{

    int arr[4][4] = {{1, 2, 3, 4},
                     {5, 6, 7, 8},
                     {9, 10, 11, 12},
                     {13, 14, 15, 16}};

    for (int i = 0; i < 4; i++)
    {
        int start = 0, end = 3;

        while (start < end)
        {
            swap(arr[i][start], arr[i][end]);
            start++;
            end--;
        }
    }
    cout << "Reversed matrix: " << endl;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
