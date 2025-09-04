#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    // Initialize a vector with unsorted elements
    vector<int> arr = {1, 8, 6, 4, 10, 45};

    int x; // Variable to store the target sum
    cout << "Enter the target sum: ";
    cin >> x;

    int n = arr.size(); // Get the size of the vector

    // Sort the array to use the two-pointer approach effectively
    sort(arr.begin(), arr.end());
    // Iterate through the array to fix the first two numbers
    for (int i = 0; i < n - 3; i++)
    {
        for (int j = i + 1; j < n - 2; j++)
        {
            int target = x - (arr[i] + arr[j]); // Adjust target for last two numbers
            int start = j + 1;
            int end = n - 1;
            // Two-pointer approach for the remaining two numbers
            while (start < end)
            {
                int sum = arr[start] + arr[end];
                if (sum == target)
                {
                    cout << "Quadriplet found: [" << arr[i] << ", " << arr[j] << ", " << arr[start] << ", " << arr[end] << "]" << endl;
                    cout << "Quadriplet found at Index: [" << i << ", " << j << ", " << start << ", " << end << "]" << endl;
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
    }

    cout << "No Quadriplet found." << endl;
    return 0;
}




