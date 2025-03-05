#include <iostream>
using namespace std;

int main()
{
    int arr[1000] = {6, 4, 12, -3, 7, 14, 28}; 
    int n = 7;                                
    int suffix[1000];                          // Array to store the suffix sums

    // Initialize the last element of the suffix array
    suffix[n-1] = arr[n - 1];

    // Calculate the suffix sums in reverse order
    for (int i = n - 2; i >= 0; i--)
    {
        suffix[i] = suffix[i + 1] + arr[i];
    }

    // Print the suffix sum array
    cout << "Suffix sum array: ";
    for (int i = 0; i < n; i++)
    {
        cout << suffix[i] << " ";
    }
    cout << endl;
    return 0;
}
