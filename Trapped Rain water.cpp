#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int trap(vector<int>& height) {
    if (height.empty()) 
    return 0;
    
    int unit = 0, start = 0, end = height.size() - 1;
    int maxL = height[start], maxR = height[end];
    
    while (start < end) {
        if (maxL < maxR) {
            unit += maxL - height[start];
            maxL = max(maxL, height[++start]);
        } else {
            unit += maxR - height[end];
            maxR = max(maxR, height[--end]);
        }
    }
    
    return unit;
}

int main() {
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    int result = trap(height);
    cout << "Trapped rain water: " << result << endl;
    return 0;
}