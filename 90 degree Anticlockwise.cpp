#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // Initialize a 4x4 matrix with values from 1 to 16
    vector<vector<int>> matrix = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };
    
    int n = matrix.size(); // Determine the size of the matrix

    // Transpose the matrix
    // Transposing involves swapping matrix[i][j] with matrix[j][i]
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    // Reverse each column to achieve a 90-degree anticlockwise rotation
    for (int j = 0; j < n; j++)
    {
        int start = 0, end = n - 1;
        
        // Swap elements from top to bottom in each column
        while (start < end)
        {
            swap(matrix[start][j], matrix[end][j]);
            start++;
            end--;
        }
    }

    // Output the transformed matrix
    cout << "Matrix after 90 degree Anticlockwise rotation:" << endl;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
