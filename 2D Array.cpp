#include <iostream>
using namespace std;

void print(int arr[][4], int row, int col)
{
    for (int i = 0; i < row; i++)
    {

        for (int j = 0; j < col; j++)

            cout << arr[i][j] << " ";
    }

};

int main()
{

    int arr[3][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};

    // i=row j=column
    for (int i = 0; i < 3; i++)
    {

        for (int j = 0; j < 4; j++)
        
            cout << arr[i][j] << " ";
        
    }
    print(arr, 3, 4);

    return 0;
}