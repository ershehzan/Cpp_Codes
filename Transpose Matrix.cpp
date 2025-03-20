#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // Define a 4x4 matrix (2D vector)
    vector<vector<int>> arr = {
        {0, 1, 2, 3},
        {4, 5, 6, 7},
        {8, 9, 10, 11},
        {12, 13, 14, 15}};

    // Declare a 2D array to store the transpose
    int trans[4][4];

    // Loop through the matrix to compute the transpose
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            trans[j][i] = arr[i][j]; // Swap rows and columns
            cout << trans[j][i] << " "; // Print transposed element
        }
        cout << endl; // New line after each row
    }
    
    return 0;
}
