#include <iostream>
using namespace std; 

int main()
{
    // Initialize an array with some integer values
    int arr[1000] = {6, 4, 12, -3, 7, 14, 28}; 

    // The number of elements in the array
    int n = 7;                                

    // Declare an array to store the suffix sums
    int suffix[1000];                          

    // Initialize the last element of the suffix array with the last element of the input array
    suffix[n - 1] = arr[n - 1];

    // Compute the suffix sums in reverse order
    for (int i = n - 2; i >= 0; i--)
    {
        // Each suffix sum element is calculated as the sum of the next suffix element and the current element
        suffix[i] = suffix[i + 1] + arr[i];
    }

    // Output the suffix sum array
    cout << "Suffix sum array: ";

    // Print all elements of the suffix sum array
    for (int i = 0; i < n; i++)
    {
        cout << suffix[i] << " ";
    }
    cout << endl; // Print a newline for better readability

    return 0; 
}
