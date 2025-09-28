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
        if (n == 0)
            return 0; // Edge case: empty height array
        
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
            if (leftmax > height[i]) { // Water can be trapped if leftmax is greater
                water += leftmax - height[i];
            } else { // Update leftmax if current height is greater
                leftmax = height[i];
            }
        }

        // Calculate trapped water on the right side
        for (int i = n - 1; i > index; i--) {
            if (rightmax > height[i]) { // Water can be trapped if rightmax is greater
                water += rightmax - height[i];
            } else { // Update rightmax if current height is greater
                rightmax = height[i];
            }
        }
        
        return water; // Return the total trapped water
    }
};

int main() {
    Solution sol;
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << "Trapped rain water: " << sol.trap(height) << endl; // Output the result
    return 0;
}

