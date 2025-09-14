#include <iostream>
using namespace std;
int main(){
    // First 2D array
    int arr1[3][3] = {1, 2, 3,
                      4, 5, 6,
                      7, 8, 9};

    // Second 2D array
    int arr2[3][3] = {1, 2, 3,
                      4, 5, 6,
                      7, 8, 9};

    // Resultant array to store element-wise division
    int ans[3][3];
    // Performing element-wise division of arr1 by arr2
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (arr2[i][j] != 0) // Avoid division by zero
                ans[i][j] = arr1[i][j] / arr2[i][j];
            else
                ans[i][j] = 0; // Assign 0 if division by zero occurs
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





