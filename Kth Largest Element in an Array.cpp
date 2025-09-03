#include <iostream>
#include <vector>
#include <queue>
using namespace std;
// Solution class
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // Min-heap of size k
        priority_queue<int, vector<int>, greater<int>> p;

        for (int i = 0; i < k; i++)
            p.push(nums[i]);

        for (int i = k; i < nums.size(); i++) {
            if (nums[i] > p.top()) {
                p.pop();
                p.push(nums[i]);
            }
        }
        return p.top();
    }
};

int main() {
    Solution sol;
    vector<int> nums = {3, 2, 1, 5, 6, 4};
    int k = 2;
    int result = sol.findKthLargest(nums, k);
    cout << "The " << k << "th largest element is: " << result << endl;

    return 0;
}





