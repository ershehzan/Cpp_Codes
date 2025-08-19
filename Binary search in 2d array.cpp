#include <iostream>
#include <vector>
using namespace std;
int main()
{
    // Initializing a 2D vector (4x4 matrix)
    vector<vector<int>> arr = {{1, 2, 3, 4},
                               {5, 6, 7, 8},
                               {9, 10, 11, 12},
                               {13, 14, 15, 16}};
    
    int x; // Variable to store the element to be searched
    cout << "Enter the element to be searched: ";
    cin >> x; // Taking user input

    int n = 4, m = 4; // Defining matrix dimensions
    int start = 0, end = n * m - 1; // Start and end pointers for binary search

    // Performing binary search in the 2D matrix
    while (start <= end)
    {
        int mid = (start + end) / 2; // Finding the middle index

        int row_index = mid / m; // Row index of mid element
        int col_index = mid % m; // Column index of mid element

        int k = arr[row_index][col_index]; // Extracting the mid element

        if (k == x) // If element is found
        {
            cout << "Element found at index: " << mid << endl;
            return 0;
        }
        else if (k < x) // If element is greater, search right half
        {
            start = mid + 1;
        }
        else // If element is smaller, search left half
        {
            end = mid - 1;
        }
    }

    cout << "Element not found in the matrix." << endl; // If element is not found
    return 0;
}

