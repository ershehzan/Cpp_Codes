#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // Initialize a 2D vector with values
    vector<vector<int>> arr = {
        {0, 1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10, 11},
        {12, 13, 14, 15, 16, 17},
        {18, 19, 20, 21, 22, 23},
        {24, 25, 26, 27, 28, 29},
        {30, 31, 32, 33, 34, 35}};

    // Initialize boundary pointers
    int top = 0, bot = arr.size() - 1;       // 'top' and 'bot' define row boundaries
    int left = 0, right = arr[0].size() - 1; // 'left' and 'right' define column boundaries

    // Loop until all elements are printed in spiral order
    while (top <= bot && left <= right)
    {
        // Print top row from left to right
        for (int j = left; j <= right; j++)
            cout << arr[top][j] << " ";
        top++; // Move top boundary down to avoid reprinting

        // Print right column from top to bottom
        for (int i = top; i <= bot; i++)
            cout << arr[i][right] << " ";
        right--; // Move right boundary left to avoid reprinting

        // Print bottom row from right to left, if there are rows remaining
        if (top <= bot)
        {
            for (int j = right; j >= left; j--)
                cout << arr[bot][j] << " ";
            bot--; // Move bottom boundary up to avoid reprinting
        }

        // Print left column from bottom to top, if there are columns remaining
        if (left <= right)
        {
            for (int i = bot; i >= top; i--)
                cout << arr[i][left] << " ";
            left++; // Move left boundary right to avoid reprinting
        }
    }

    // End the output with a newline character
    cout << endl;
    return 0;
}
