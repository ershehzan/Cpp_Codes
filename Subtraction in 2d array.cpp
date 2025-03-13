#include <iostream>
using namespace std;

int main()
{
    // First 2D array
    int arr1[3][3] = {11, 23, 33,
                      41, 55, 61,
                      74, 85, 99};

    // Second 2D array
    int arr2[3][3] = {1, 2, 3,
                      4, 5, 6,
                      7, 8, 9};

    // Resultant array to store element-wise subtraction
    int ans[3][3];

    // Performing element-wise subtraction of arr2 from arr1
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            ans[i][j] = arr1[i][j] - arr2[i][j];
        }
    }

    // Printing the resultant array
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl; // Print new line for better readability
    }

    return 0;
}
