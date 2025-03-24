#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<vector<int>> matrix = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}};
    int n = matrix.size();

    // Transpose the matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
// reverse the matrix
    for (int j = 0; j < n; j++)
    {

        int start = 0, end = n - 1;

        while (start < end)
        {
            swap(matrix[start][j], matrix[end][j]);
            start++;
            end--;
        }
    }

    cout << "Matrix after 90 degree Anticlock wise rotation:" << endl;
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