#include <iostream>
using namespace std; 
int main(){
    // First 3x3 2D array
    int arr1[3][3] = {1, 2, 3,
                      4, 5, 6,
                      7, 8, 9};

    // Second 3x3 2D array
    int arr2[3][3] = {11, 23, 33,
                      41, 55, 61,
                      74, 85, 99};

    // Array to store the sum of arr1 and arr2
    int ans[3][3];

    // Performing element-wise addition of arr1 and arr2
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++) // Loop through columns
        {
            ans[i][j] = arr1[i][j] + arr2[i][j]; // Add corresponding elements
        }
    }
    // Printing the resulting array
    cout << "Sum of the two 2D arrays:\n";
    for (int i = 0; i < 3; i++) // Loop through rows
    {
        for (int j = 0; j < 3; j++) // Loop through columns
        {
            cout << ans[i][j] << " "; // Print each element
        }
        cout << endl; // Move to the next line after each row
    }
    return 0;
}






