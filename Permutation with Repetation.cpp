#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
 * This function generates all unique permutations of the given array.
 * It uses recursion and backtracking to explore all possible permutations.
 *
 * Parameters:
 * - arr: The input array of integers for which permutations are to be generated
 * - ans: A 2D vector to store all unique permutations
 * - index: The current index being processed in the array
 * - n: The size of the input array
 */
void permute(vector<int> &arr, vector<vector<int>> &ans, int index, int n)
{
    // Base case: If the current index reaches the size of the array, 
    // the current permutation is complete and should be added to the result.
    if (index == n)
    {
        ans.push_back(arr); // Add the current permutation to the result
        return;
    }

    // Boolean vector to track used elements at the current recursion level.
    // The range of integers is assumed to be from -10 to +10, 
    // so the size is set to 21 (to accommodate all possible values).
    vector<bool> use(21, 0);

    // Iterate through the array starting from the current index.
    for (size_t i = index; i < arr.size(); i++)
    {
        // Check if the current element has already been used at this index.
        // This ensures that duplicate permutations are avoided.
        if (use[arr[i] + 10] == 0)
        {
            // Swap the current element with the element at the current index.
            swap(arr[i], arr[index]);

            // Recursive call to generate permutations for the next index.
            permute(arr, ans, index + 1, n);

            // Backtrack by swapping the elements back to their original positions.
            swap(arr[i], arr[index]);

            // Mark the current element as used for this recursion level.
            use[arr[i] + 10] = 1;
        }
    }
}

int main()
{
    // Input array containing integers (with possible duplicates).
    vector<int> arr = {1, 2, 2, 1};
    int n = arr.size(); // Size of the input array.

    // A 2D vector to store all unique permutations.
    vector<vector<int>> ans;

    // Generate all unique permutations starting from index 0.
    permute(arr, ans, 0, n);

    // Print all the generated permutations.
    for (size_t i = 0; i < ans.size(); i++)
    {
        for (size_t j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " "; // Print each element in the permutation.
        }
        cout << endl; // Newline after each permutation.
    }

    return 0; // Exit the program successfully.
}
