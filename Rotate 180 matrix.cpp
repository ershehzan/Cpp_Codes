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
    
    // Rotate the matrix 180 degrees
    // First, mirror the matrix vertically
    for (int j = 0; j < n; j++)
    {
        int start = 0, end = n - 1;
        while (start < end)
        {
            // Swap the elements in the column
            swap(matrix[start][j], matrix[end][j]);
            start++;
            end--;
        }
    }

    // Then, mirror the matrix horizontally
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
