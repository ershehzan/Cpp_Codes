#include <iostream>
using namespace std;

int main()
{
    int n, k;
    
    // Taking input for the size of the array
    cout << "Enter the size of the array: ";
    cin >> n;
    
    int arr[n];
    
    // Taking input for array elements
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    
    // Taking input for the required difference
    cout << "Enter the difference: ";
    cin >> k;
    
    int i = 0, j = 1;
    
    // Using two-pointer technique to find the pair with the given difference
    while (i < n && j < n)
    {
        if (i != j && arr[j] - arr[i] == k) // If the difference matches the given value
        {
            cout << "Pair found at index " << "[" << i << " and " << j << "]" << endl;
            return 0; // Exit after finding the first pair
        }
        else if (arr[j] - arr[i] < k) // If difference is less, increase j to get a larger difference
        {
            j++;
        }
        else // If difference is more, increase i to reduce the difference
        {
            i++;
        }
    }
    
    // If no such pair is found
    cout << "Pair not found" << endl;
    return 0;
}
