

// Function to calculate the amount of trapped rainwater
// Time Complexity: O(n) - We traverse the height array once using the two-pointer approach
// Space Complexity: O(1) - We use only a few extra variables, independent of input size


#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int trap(vector<int>& height) {
    if (height.empty()) // Edge case: if the height array is empty, return 0
        return 0;
    
    int unit = 0; // Variable to store the total trapped water
    int start = 0, end = height.size() - 1; // Two pointers: start (left) and end (right)
    int maxL = height[start], maxR = height[end]; // Max heights from the left and right
    
    // Two-pointer approach to calculate trapped water
    while (start < end) {
        if (maxL < maxR) { // Process the left side if maxL is smaller
            unit += maxL - height[start]; // Water trapped at this position
            maxL = max(maxL, height[++start]); // Update maxL for the next position
        } else { // Process the right side if maxR is smaller or equal
            unit += maxR - height[end]; // Water trapped at this position
            maxR = max(maxR, height[--end]); // Update maxR for the next position
        }
    }
    
    return unit; // Return the total trapped water
}

int main() {
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1}; // Example input
    int result = trap(height); // Call the function
    cout << "Trapped rain water: " << result << endl; // Output the result
    return 0;
}
