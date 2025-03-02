#include <iostream>
#include <climits>
using namespace std;

int main()
{
    int arr[1000]; // Array to store elements
    int n; // Variable to store number of elements
    
    cout << "Enter the index: ";
    cin >> n;
    
    cout << "Enter the Elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i]; // Taking input for array elements
    }
    
    int ans = INT_MIN; // Initializing with the smallest possible integer value
    
    // Finding the maximum value in the array
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > ans)
            ans = arr[i]; // Updating max value if current element is greater
    }

    cout << "The MAX Element in Array is : " << ans; // Displaying the result

    return 0;
}
