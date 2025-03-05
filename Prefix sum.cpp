#include <iostream> 
using namespace std; 

int main()
{
    // Initialize an array with some integer values
    int arr[1000] = {6, 4, 12, -3, 7, 14, 28}; 
    
    // The number of elements in the array
    int n = 7;

    // Declare a prefix sum array to store cumulative sums
    int prefix[1000];

    // The first element of the prefix sum array is the same as the first element of the input array
    prefix[0] = arr[0];

    // Compute the prefix sum for the rest of the elements
    for (int i = 1; i < n; i++)
    {
        // Each prefix sum element is the sum of the previous prefix sum and the current element
        prefix[i] = prefix[i - 1] + arr[i];
    }

    // Output the prefix sum array
    cout << "Prefix sum array: ";

    // Print all elements of the prefix sum array
    for (int i = 0; i < n; i++)
    {
        cout << prefix[i] << " ";
    }

    return 0; 
}
