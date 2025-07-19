#include <iostream>
#include <vector>
using namespace std;

// Include the Solution class
class Solution {
  public:

  void heapify(vector<int>& ans, int index, int n) {
      int largest = index;

      while (index < n) {
          int left = 2 * index + 1;
          int right = 2 * index + 2;
          
          if (left < n && ans[left] > ans[largest]) {
              largest = left;
          }
          if (right < n && ans[right] > ans[largest]) {
              largest = right;
          }
          if (largest != index) {
              swap(ans[largest], ans[index]);
              index = largest;
        
            } 
            else {
              break;
          }
      }
  }

  vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
      vector<int> ans;

      // Merge both arrays
      for (int i = 0; i < n; i++)
          ans.push_back(a[i]);
      for (int i = 0; i < m; i++)
          ans.push_back(b[i]);
      
      int size = ans.size();
      
      // Build max heap
      for (int i = size / 2 - 1; i >= 0; i--) {
          heapify(ans, i, size);
      }

      return ans;
  }
};

int main() {
    vector<int> heap1 = {10, 5, 6};
    vector<int> heap2 = {7, 9};
    int n = heap1.size();
    int m = heap2.size();

    Solution obj;
    vector<int> mergedHeap = obj.mergeHeaps(heap1, heap2, n, m);

    cout << "Merged Max Heap: ";
    for (int val : mergedHeap) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
