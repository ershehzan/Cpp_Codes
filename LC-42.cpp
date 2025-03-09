// Find the amount of water that can be trapped between the buildings
// Time Complexity: O(n)
// Space Complexity: O(1)

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0) return 0; // Edge case: empty height array
        
        int leftmax = 0, rightmax = 0, maxheight = height[0], index = 0;
        int water = 0;

        // Find the maximum height building and its index
        for (int i = 1; i < n; i++) {
            if (maxheight < height[i]) {
                maxheight = height[i];
                index = i;
            }
        }

        // Calculate trapped water on the left side
        for (int i = 0; i < index; i++) {
            if (leftmax > height[i]) {
                water += leftmax - height[i];
            } else {
                leftmax = height[i];
            }
        }

        // Calculate trapped water on the right side
        for (int i = n - 1; i > index; i--) {
            if (rightmax > height[i]) {
                water += rightmax - height[i];
            } else {
                rightmax = height[i];
            }
        }
        
        return water;
    }
};

int main() {
    Solution sol;
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << "Trapped rain water: " << sol.trap(height) << endl;
    return 0;
}