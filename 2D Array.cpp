#include <iostream>
using namespace std;

// Function to print a 2D array
void print(int arr[][4], int row, int col)
{
    // Loop through each row
    for (int i = 0; i < row; i++)
    {
        // Loop through each column
        for (int j = 0; j < col; j++)
            cout << arr[i][j] << " "; // Print each element
    }
}

int main()
{
    // Initializing a 3x4 2D array
    int arr[3][4] = {1, 2, 3, 4, 
                     5, 6, 7, 8, 
                     9, 10, 11, 12};

    // Printing the array using a nested loop
    // i represents row index, j represents column index
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
            cout << arr[i][j] << " "; // Print each element
    }

    // Calling the print function to print the array again
    print(arr, 3, 4);

    return 0;
}
