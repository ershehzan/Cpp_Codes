#include <iostream>
#include <vector>
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

    int top = 0, bot = arr.size() - 1, left = 0, right = arr[0].size() - 1;
    while (top <= bot && left <= right)
    {
        // Print top row
        for (int j = left; j <= right; j++)
            cout << arr[top][j] << " ";
        top++;

        // Print right column
        for (int i = top; i <= bot; i++)
            cout << arr[i][right] << " ";
        right--;

        // Print bottom row
        if (top <= bot)
        { // Check to prevent duplicate row traversal
            for (int j = right; j >= left; j--)
                cout << arr[bot][j] << " ";
            bot--;
        }

        // Print left column
        if (left <= right)
        { // Check to prevent duplicate column traversal
            for (int i = bot; i >= top; i--)
                cout << arr[i][left] << " ";
            left++;
        }
    }

    cout << endl;
    return 0;
}