#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    // Defining a 2D vector (matrix) with 3 rows and 4 columns
    vector<vector<int>> matrix = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}};

    cout << "Wave Form Traversal:" << endl;

    // Iterating through each column
    for (int j = 0; j < 4; j++)
    {
        // If the column index is even, traverse top to bottom
        if (j % 2 == 0)
        {
            for (int i = 0; i < 3; i++)
            {
                cout << matrix[i][j] << " ";
            }
        }
        // If the column index is odd, traverse bottom to top
        else
        {
            for (int i = 2; i >= 0; i--)
            {
                cout << matrix[i][j] << " ";
            }
        }
    }
    
    return 0;
}
