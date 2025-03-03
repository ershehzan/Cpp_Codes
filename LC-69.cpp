#include<iostream>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        // Binary search approach to find the square root of x
        int start = 0, end = x, mid, ans;
        
        while (start <= end) {
            mid = start + (end - start) / 2; // Avoids overflow
            
            // If mid squared is exactly x, return mid
            if (mid * mid == x) {
                return mid;
            }
            // If mid squared is less than x, store mid as potential answer and move right
            else if (mid * mid < x) {
                ans = mid;
                start = mid + 1;
            }
            // If mid squared is greater than x, move left
            else {
                end = mid - 1;
            }
        }
        
        return ans; // Return the integer part of the square root
    }
};

int main() {
    Solution s;
}
