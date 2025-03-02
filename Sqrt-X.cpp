#include <iostream>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        // Solution starts here
        int start = 0, end = x, mid, ans;
        
        // Implementing binary search to find the square root
        while (start <= end) {
            mid = start + (end - start) / 2; // Prevents integer overflow
            
            if (mid * mid == x) {
                return mid; // If mid squared is exactly x, return mid
            }
            else if (mid * mid < x) {
                ans = mid; // Store the potential floor value of sqrt(x)
                start = mid + 1; // Move to the right half
            }
            else {
                end = mid - 1; // Move to the left half
            }
        }
        
        return ans; // Return the integer part of the square root
        // End here
    }
};

int main() {
    Solution s; // Creating an instance of the Solution class
    return 0;
}
