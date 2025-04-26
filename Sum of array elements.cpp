#include <iostream>
using namespace std;
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 11};


    int n = 10;

    // Variable to store the sum of all elements in the array
    int sum = 0;

    // Loop through the array to calculate the sum of its elements
    for (int i = 0; i < n; i++) {
        // Add the current element to the sum
        sum += arr[i];
    }

    // Print the sum of all elements in the array
    cout << "Sum of all elements in the array: " << sum << endl;

    return 0;
}