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
    
    // Step 1: Transpose the matrix (swap rows with columns)
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            // Swap the elements at position (i, j) with (j, i)
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    
    // Step 2: Reverse each row of the transposed matrix
    for (int i = 0; i < n; i++)
    {
        int start = 0, end = n - 1;
        while (start < end)
        {
            // Swap the elements in the row
            swap(matrix[i][start], matrix[i][end]);
            start++;
            end--;
        }
    }
    
    // Step 3: Transpose the matrix again
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            // Swap the elements at position (i, j) with (j, i)
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    
    // Step 4: Reverse each row of the transposed matrix again to complete the 180 degree rotation
    for (int i = 0; i < n; i++)
    {
        int start = 0, end = n - 1;
        while (start < end)
        {
            // Swap the elements in the row
            swap(matrix[i][start], matrix[i][end]);
            start++;
            end--;
        }
    }
    
    // Output the matrix after 180 degree rotation
    cout << "Matrix after 180 degree rotation:" << endl;
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
