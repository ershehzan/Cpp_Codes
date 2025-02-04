#include <iostream>
#include <climits> // Include the library for INT_MAX and INT_MIN

using namespace std;

int main()
{
    int arr[1000];
    int n, i;

    cout << "Enter the index: ";
    cin >> n;

    cout << "Enter the Elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int ans = INT_MAX; // Initialize ans with the maximum possible integer value

    // Find the minimum value in the array
    for (i = 0; i < n; i++)
    {
        if (arr[i] < ans)
            ans = arr[i]; // Update ans if a smaller value is found
    }

    // Display the minimum value
    cout << "Min value is : " << ans << endl;

    ans = INT_MIN; // Reset ans to the minimum possible integer value

    // Find the maximum value in the array
    for (i = 0; i < n; i++)
    {
        if (arr[i] > ans)
            ans = arr[i]; // Update ans if a larger value is found
    }

    // Display the maximum value
    cout << "Max value is : " << ans << endl;

    return 0;
}
