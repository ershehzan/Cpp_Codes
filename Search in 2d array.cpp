#include <iostream>
using namespace std;

int main()
{
    // Initializing a 3x4 2D array
    int arr[3][4] = {1, 2, 3, 4, 
                     5, 6, 7, 8, 
                     9, 10, 11, 12};

    int x; // Variable to store the element to be searched
    cout << "Enter the element to be searched: ";
    cin >> x; // Taking user input

    // Loop through each row
    for (int i = 0; i < 3; i++)
    {
        // Loop through each column
        for (int j = 0; j < 4; j++)
        {
            // Check if the current element matches the searched element
            if (arr[i][j] == x)
            {
                cout << "Element found at row " << i << " and column " << j << endl;
                return 0; // Exit the program once the element is found
            }
        }
    }

    // If element is not found in the array
    cout << "Element not found";
    return 0;
}
