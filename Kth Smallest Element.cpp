#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Include the Solution class
class Solution {
  public:
    // arr : given array
    // k : find kth smallest element and return using this function
    int kthSmallest(vector<int> &arr, int k) {
        priority_queue<int> p;

        for (int i = 0; i < k; i++) {
            p.push(arr[i]);
        }

        for (int i = k; i < arr.size(); i++) {
            if (p.top() > arr[i]) {
                p.pop();
                p.push(arr[i]);
            }
        }

        return p.top();
    }
};

int main() {
    Solution sol;

    vector<int> arr = {7, 10, 4, 3, 20, 15};
    int k = 3;

    int result = sol.kthSmallest(arr, k);

    cout << "The " << k << "rd smallest element is: " << result << endl;

    return 0;
}
