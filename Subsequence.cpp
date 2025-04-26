// Program to generate the power set (all possible subsets) of a set

#include <iostream>
#include <vector>
using namespace std;

// Recursive function to generate all subsequences (subsets) of an array
// arr[]     -> Input array
// index     -> Current index in the array
// n         -> Size of the array
// ans       -> Vector to store all subsets (result)
// temp      -> Temporary vector to store the current subset being formed
void subseq(int arr[], int index, int n, vector<vector<int>> &ans, vector<int> temp)
{
    // Base case: If we reach the end of the array, add the current subset to the result
    if (index == n)
    {
        ans.push_back(temp); // Add the current subset to the result
        return;              // Return to explore other subsets
    }

    // Recursive case 1: Exclude the current element and move to the next element
    subseq(arr, index + 1, n, ans, temp);

    // Recursive case 2: Include the current element in the subset and move to the next element
    temp.push_back(arr[index]); // Add the current element to the subset
    subseq(arr, index + 1, n, ans, temp);
}

int main()
{
    // Input array
    int arr[] = {1, 2, 3};
    int n = 3; // Size of the array

    // Vector to store all subsets
    vector<vector<int>> ans;

    // Temporary vector to store the current subset being formed
    vector<int> temp;

    // Generate all subsets using the recursive function
    subseq(arr, 0, n, ans, temp);

    // Print the power set (all subsets)
    cout << "The power set is: " << endl;

    // Iterate through all subsets in ans
    for (size_t i = 0; i < ans.size(); i++)
    {
        for (size_t j = 0; j < ans[i].size(); j++)
        {
            // Print each element of the subset
            cout << "{" << ans[i][j] << "}" << " ";
        }
        cout << endl; // Print a newline after each subset
    }

    return 0;
}
