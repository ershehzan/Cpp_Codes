#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to generate all unique permutations of the input vector
// Parameters:
// - arr: The input vector of integers for which permutations are to be generated
// - ans: A 2D vector to store all unique permutations
// - index: The current index being processed
// - n: The size of the input vector
void permute(vector<int> &arr, vector<vector<int>> &ans, int index, int n)
{
    // Base case: If index reaches the end of the array, add the current permutation to the result
    if (index == n)
    {
        ans.push_back(arr); // Store the current permutation
        return;
    }

    // Boolean vector to ensure no duplicate elements are used at the current position
    vector<bool> use(21, 0); // Adjusted for -10 to +10 range, as stated in the problem constraints

    // Iterate through the array starting from the current index
    for (size_t i = index; i < arr.size(); i++)
    {
        // Check if the current element has already been used at this index
        if (use[arr[i] + 10] == 0)
        {
            // Swap the current element with the element at the current index
            swap(arr[i], arr[index]);

            // Recursive call to generate permutations for the next index
            permute(arr, ans, index + 1, n);

            // Backtrack by swapping the elements back to their original positions
            swap(arr[i], arr[index]);

            // Mark the current element as used
            use[arr[i] + 10] = 1;
        }
    }
}

int main()
{
    // Input array containing integers (with possible duplicates)
    vector<int> arr = {1, 2, 2, 1};
    int n = arr.size(); // Size of the input array

    // 2D vector to store all unique permutations
    vector<vector<int>> ans;

    // Generate all unique permutations starting from index 0
    permute(arr, ans, 0, n);

    // Print all generated permutations
    for (size_t i = 0; i < ans.size(); i++)
    {
        for (size_t j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " "; // Print each element in the permutation
        }
        cout << endl; // Newline after each permutation
    }

    return 0; // Exit the program
}
