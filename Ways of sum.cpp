#include <iostream>
using namespace std;

// Function to count the number of ways to reach the sum
int way(int arr[], int m, int sum)
{
    if (sum == 0)
    {
        return 1;
    }
    if (sum < 0)
    {
        return 0;
    }
    int ans = 0;
    for (int i = 0; i < m; i++)
    {
        ans += way(arr, m, sum - arr[i]);
    }
    return ans;
}

int main()
{
    int arr[] = {1, 6, 5};
    int n = 3;      // number of elements in the array
    int target = 7; // target sum

    cout << "The number of ways to get the sum is: " << way(arr, n, target) << endl;
    return 0;
}
