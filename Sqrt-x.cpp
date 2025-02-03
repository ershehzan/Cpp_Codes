#include <iostream>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        long long start = 0, end = x, ans = 0;
        
        while (start <= end) {
            long long mid = start + (end - start) / 2;
            long long square = (long long)mid * mid;  // Explicitly cast mid to long long
            
            if (square == x) {
                return mid;
            } else if (square < x) {
                ans = mid;
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return ans;
    }
};

int main() {
    int x;
    cout << "Enter a number: ";
    cin >> x;
    
    Solution s1;  // Correctly instantiate the class
    int result = s1.mySqrt(x);  // Call the function

    cout << "Square root of " << x << " is: " << result << endl;  // Print result
    return 0;
}
