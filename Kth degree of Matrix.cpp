#include <iostream>
#include <vector>
using namespace std;
// Function to rotate the matrix 90 degrees clockwise
void rotate(vector<vector<int>> &matrix)
{
    int n = matrix.size();

    // Step 1: Transpose the matrix (convert rows to columns)
    // This swaps elements across the diagonal
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    // Step 2: Reverse each row to get the final rotated matrix
    // This mirrors the elements horizontally
    for (int i = 0; i < n; i++)
    {
        int start = 0, end = n - 1;
        while (start < end)
        {
            swap(matrix[i][start], matrix[i][end]);
            start++;
            end--;
        }
    }
}

// Function to print the matrix
void printMatrix(const vector<vector<int>> &matrix)
{
    int n = matrix.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    // Initialize a 4x4 matrix
    vector<vector<int>> matrix = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}};

    int k;
    cout << "Enter the value of k: ";
    cin >> k;

    // Normalize k to be within the range 0 to 3
    k = k % 4; // Since rotating 4 times results in the original matrix
    if (k < 0) // Handle negative k values (optional in some cases)
    {
        k += 4;
    }

    // Rotate the matrix k times
    for (int i = 0; i < k; i++)
    {
        rotate(matrix);
    }

    // Display the rotated matrix
    cout << "Rotated Matrix: " << endl;
    printMatrix(matrix);

    return 0;
}

