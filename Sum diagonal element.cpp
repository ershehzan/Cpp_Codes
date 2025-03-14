#include <iostream>
using namespace std;

int main()
{
    // Initialize a 4x4 matrix with given values
    int arr[4][4] = {{1, 2, 3, 4},
                     {19, 5, 6, 72},
                     {6, 8, 9, 10},
                     {15, 12, 13, 14}};

    // Variables to store the sum of the primary and secondary diagonals
    int first = 0, second = 0;

    // Loop through each row to calculate diagonal sums
    for (int i = 0; i < 4; i++)
    {
        first += arr[i][i];           // Summing elements of the primary diagonal
        second += arr[i][4 - i - 1];  // Summing elements of the secondary diagonal
    }

    // Alternative approach using a while loop (commented out)
    // This does the same thing as the for loop above for the secondary diagonal
    /*
    int i = 0, j = 3;
    while (j >= 0)
    {
        second += arr[i][j];
        i++;
        j--;
    }
    */

    // Print the calculated diagonal sums
    cout << "Sum of first diagonal: " << first << endl;
    cout << "Sum of second diagonal: " << second << endl;

    return 0;
}
