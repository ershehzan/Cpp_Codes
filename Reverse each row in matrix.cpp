#include <iostream>
using namespace std;

int main()
{
    // Initializing a 4x4 matrix
    int arr[4][4] = {{1, 2, 3, 4},
                     {5, 6, 7, 8},
                     {9, 10, 11, 12},
                     {13, 14, 15, 16}};

    // Loop through each row to reverse its elements
    for (int i = 0; i < 4; i++)
    {
        int start = 0, end = 3; // Pointers for swapping elements

        while (start < end)
        {
            // Swap the elements at start and end positions
            swap(arr[i][start], arr[i][end]);
            start++;
            end--;
        }
    }

    // Display the reversed matrix
    cout << "Reversed matrix: " << endl;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << arr[i][j] << " "; // Print each element
        }
        cout << endl; // Move to the next row
    }
    
    return 0;
}
