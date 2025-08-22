#include <iostream>
#include <climits>
using namespace std;

int main(){
    // Initialize a 3x3 matrix with given values
    int arr[3][3] = {11, 23, 33,
                     41, 55, 61,
                     74, 85, 99};

    // Variables to store the maximum row sum and the corresponding index
    int sum = INT_MIN, index = -1;

    // Loop through each row of the matrix
    for (int i = 0; i < 3; i++)
    {
        int total = 0; // Variable to store the sum of the current row

        // Loop through each column and calculate the sum of the current row
        for (int j = 0; j < 3; j++)
            total += arr[i][j];

        // Check if the current row's sum is greater than the maximum found so far
        if (total > sum)
        {
            sum = total; // Update the maximum sum
            index = i;   // Store the index of the row with the maximum sum
        }
    }

    // Print the index of the row with the maximum sum
    cout << index;

    return 0;
}

