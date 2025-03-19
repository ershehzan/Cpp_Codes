#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    vector<vector<int>> arr = {
        {0, 1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10, 11},
        {12, 13, 14, 15, 16, 17},
        {18, 19, 20, 21, 22, 23},
        {24, 25, 26, 27, 28, 29},
        {30, 31, 32, 33, 34, 35}};

    int top = 0, bot = 5, left = 0, right = 5;
    while (top <= bot && left <= right)
    {
        for (int j = left; j < right; j++)
            cout << arr[top][j] << " ";
        top++;

        for (int i = top; i <= bot; i++)
            cout << arr[i][right] << " ";
        right--;

        for (int j = right; j >= left; j--)
            cout << arr[bot][j] << " ";
        bot--;

        for (int i = bot; i >= top; i--)
            cout << arr[i][left] << " ";
        left++;
    }
    return 0;
}