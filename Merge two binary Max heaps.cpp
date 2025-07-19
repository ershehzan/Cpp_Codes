#include <iostream>
#include <vector>
using namespace std;

// Solution class that includes heapify and mergeHeaps functions
class Solution {
  public:

  // Function to maintain the max heap property for a given subtree rooted at index
  void heapify(vector<int>& ans, int index, int n) {
      int largest = index;

      // Loop to ensure that subtree rooted at index becomes a max heap
      while (index < n) {
          int left = 2 * index + 1;  // left child
          int right = 2 * index + 2; // right child
          
          // If left child is greater than current largest, update largest
          if (left < n && ans[left] > ans[largest]) {
              largest = left;
          }

          // If right child is greater than current largest, update largest
          if (right < n && ans[right] > ans[largest]) {
              largest = right;
          }

          // If either child is greater, swap and continue heapifying
          if (largest != index) {
              swap(ans[largest], ans[index]); // Move larger child up
              index = largest; // Continue heapifying at new index
            } 
            else {
              // If already heap, break
              break;
          }
      }
  }

  // Function to merge two max-heaps into one max-heap
  vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
      vector<int> ans;

      // Step 1: Merge both heaps into one array
      for (int i = 0; i < n; i++)
          ans.push_back(a[i]);
      for (int i = 0; i < m; i++)
          ans.push_back(b[i]);
      
      int size = ans.size();

      // Step 2: Convert the merged array into a max-heap using heapify
      // Start from the last non-leaf node and heapify each node upwards
      for (int i = size / 2 - 1; i >= 0; i--) {
          heapify(ans, i, size);
      }

      return ans; // Return the merged max heap
  }
};

// Main function to test the mergeHeaps method
int main() {
    vector<int> heap1 = {10, 5, 6}; // First max-heap
    vector<int> heap2 = {7, 9};     // Second max-heap
    int n = heap1.size();
    int m = heap2.size();

    Solution obj;
    
    // Merge the two heaps
    vector<int> mergedHeap = obj.mergeHeaps(heap1, heap2, n, m);

    // Print the resulting max-heap
    cout << "Merged Max Heap: ";
    for (int val : mergedHeap) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
