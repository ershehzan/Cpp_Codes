#include <iostream>
using namespace std;

/*
 * Function to calculate the number of ways to reach a target sum using elements from a given array.
 * This function uses recursion to explore all possible combinations of elements that sum up to the target.
 *
 * Parameters:
 * - arr: The array of integers that can be used to form the sum.
 * - m: The size of the array.
 * - sum: The target sum that needs to be achieved.
 *
 * Returns:
 * - An integer representing the total number of ways to form the target sum.
 */
int way(int arr[], int m, int sum)
{
    // Base case: If the target sum becomes zero, a valid combination is found.
    if (sum == 0)
    {
        return 1; // Return 1 to count this combination.
    }

    // Base case: If the target sum becomes negative, this is not a valid combination.
    if (sum < 0)
    {
        return 0; // Return 0 as no valid way exists for this branch.
    }

    // Initialize a variable to store the total number of ways.
    int ans = 0;

    // Iterate through the array to consider each element as part of the solution.
    for (int i = 0; i < m; i++)
    {
        // Recursive call: Reduce the target sum by the current array element and explore further.
        ans += way(arr, m, sum - arr[i]);
    }

    // Return the total number of ways for the current target sum.
    return ans;
}

int main()
{
    // Array of integers that can be used to form the target sum.
    int arr[] = {1, 6, 5};

    // Number of elements in the array.
    int n = 3;

    // The target sum that needs to be achieved.
    int target = 7;

    // Call the recursive function and display the result.
    cout << "The number of ways to get the sum is: " << way(arr, n, target) << endl;

    return 0; // Exit the program successfully.
}
