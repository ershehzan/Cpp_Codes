// Include necessary header files
#include <iostream>
#include <vector> // For using the vector container
using namespace std;

// Function to calculate the sum of all subsets of an array
// Parameters:
// - arr[]: The input array
// - index: The current index in the array being processed
// - n: Total number of elements in the array
// - sum: The current sum of the subset being processed
// - ans: A vector to store the sums of all subsets
void subsetsum(int arr[], int index, int n, int sum, vector<int>& ans)
{
    // Base case: If we have processed all elements in the array
    if (index == n)
    {
        // Store the sum of the current subset in the results vector
        ans.push_back(sum);
        return;
    }

    // Recursive case 1: Exclude the current element from the subset
    subsetsum(arr, index + 1, n, sum, ans);

    // Recursive case 2: Include the current element in the subset
    subsetsum(arr, index + 1, n, sum + arr[index], ans);
}

int main()
{
    // Input array
    int arr[] = {3, 4, 5};
    int n = 3; // Number of elements in the array

    // Vector to store the sums of all subsets
    vector<int> ans;

    // Inform the user about the purpose of the program
    cout << "The sum of all subsets is: " << endl;

    // Call the subset sum function starting from index 0 and initial sum 0
    subsetsum(arr, 0, n, 0, ans);

    // Print all the sums of subsets
    for (size_t i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " "; // Output each subset sum
    }
    cout << endl; // End the output line

    return 0; // Indicate successful program execution
}
