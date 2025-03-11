#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    // Initialize a vector with unsorted elements
    vector<int> arr = {1, 8, 6, 4, 10, 45};

    int x; // Variable to store the target sum
    cout << "Enter the target sum: ";
    cin >> x;

    int n = arr.size(); // Get the size of the vector

    // Sort the array to use the two-pointer approach effectively
    sort(arr.begin(), arr.end());

    for (int i = 0; i < n - 2; i++)
    {
        int target = x - arr[i];
        int k = i + 1;
        int start = i + 2;
        int end = n - 1;

        while (start < end)
        {
            int sum = arr[start] + arr[end] + arr[k];
            if (sum == target)
            {
                cout << "Quadriplet found: [" << arr[i] << ", " << arr[start] << ", " << arr[end] << ", " << arr[k] << "]" << endl;
                cout << "Quadriplet found at Index: [" << i << ", " << start << ", " << end << ", " << k << "]" << endl;
                return 0;
            }
            else if (sum < target)
            {
                start++;
            }
            else
            {
                end--;
            }
        }
    }

    cout << "No Quadriplet found." << endl;
    return 0;
}
