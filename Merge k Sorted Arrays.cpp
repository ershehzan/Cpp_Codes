#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Partition function for QuickSort
    // It places the pivot element at the correct position and
    // arranges smaller elements to the left and larger to the right.
    int partition(vector<int>& arr, int start, int end) {
        int pivot = arr[end];   // Choosing the last element as pivot
        int pos = start;        // Position for swapping

        for (int i = start; i < end; ++i) {
            if (arr[i] <= pivot) {
                swap(arr[i], arr[pos]);  // Swap if element is smaller than pivot
                pos++;
            }
        }
        swap(arr[pos], arr[end]); // Put pivot in its correct position
        return pos;               // Return pivot's final index
    }

    // Recursive QuickSort function
    void QuickSort(vector<int>& arr, int start, int end) {
        if (start >= end) return; // Base case: one or no element

        // Partition the array and sort the subarrays
        int pivot = partition(arr, start, end);
        QuickSort(arr, start, pivot - 1);
        QuickSort(arr, pivot + 1, end);
    }

    // Function to merge K sorted arrays and return a sorted result
    vector<int> mergeKArrays(vector<vector<int>> arr, int K) {
        vector<int> ans;

        // Flatten the 2D vector into a single 1D array
        for (int i = 0; i < K; i++) {
            for (int j = 0; j < arr[i].size(); j++) {
                ans.push_back(arr[i][j]);
            }
        }

        // Sort the flattened array using QuickSort
        QuickSort(ans, 0, ans.size() - 1);

        return ans; // Return the merged and sorted array
    }
};

// Utility function to print the vector
void printVector(const vector<int>& vec) {
    for (int num : vec) {
        cout << num << " ";
    }
    cout << endl;
}

// Main function to test the mergeKArrays function
int main() {
    Solution sol;

    // Input: K sorted arrays
    vector<vector<int>> arrays = {
        {1, 5, 7},
        {2, 3, 6},
        {0, 9, 10}
    };

    int K = arrays.size(); // Number of arrays

    // Merging and sorting
    vector<int> result = sol.mergeKArrays(arrays, K);

    // Output result
    cout << "Merged and Sorted Array: ";
    printVector(result);

    return 0;
}
