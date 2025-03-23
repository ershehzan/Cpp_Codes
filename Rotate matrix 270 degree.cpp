// Rotate Matrix 90 degree Anticlockwise
// Same as Rotate Matrix 270 degree Clockwise

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // Define a 4x4 matrix
    vector<vector<int>> matrix = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}};
    
    // Get the size of the matrix (number of rows or columns)
    int n = matrix.size();
    
    // Step 1: Rotate the matrix 180 degrees
    // First, mirror the matrix vertically (swap elements along the vertical axis)
    for (int j = 0; j < n; j++)
    {
        int start = 0, end = n - 1;
        while (start < end)
        {
            // Swap the elements in the same column but different rows
            swap(matrix[start][j], matrix[end][j]);
            start++;
            end--;
        }
    }

    // Then, mirror the matrix horizontally (swap elements along the horizontal axis)
    for (int i = 0; i < n; i++)
    {
        int start = 0, end = n - 1;
        while (start < end)
        {
            // Swap the elements in the same row but different columns
            swap(matrix[i][start], matrix[i][end]);
            start++;
            end--;
        }
    }

    // Step 2: Transpose the matrix (convert rows into columns)
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            // Swap the elements at position (i, j) with (j, i)
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    
    // Step 3: Reverse each row of the transposed matrix
    for (int i = 0; i < n; i++)
    {
        int start = 0, end = n - 1;
        while (start < end)
        {
            // Swap the elements within the same row
            swap(matrix[i][start], matrix[i][end]);
            start++;
            end--;
        }
    }
    
    // Output the matrix after 270-degree rotation (90 degrees anticlockwise)
    cout << "Matrix after 270-degree rotation:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
