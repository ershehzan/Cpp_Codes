#include <iostream>
using namespace std;

// Define a class named Solution
class Solution {
public:
    // Function to compute the integer square root of a given number x
    int mySqrt(int x) {
        long long start = 0, end = x, ans = 0; // Initialize search range and answer variable
        
        // Implement binary search to find the square root
        while (start <= end) {
            long long mid = start + (end - start) / 2; // Calculate mid to avoid overflow
            long long square = (long long)mid * mid;  // Explicitly cast mid to long long to prevent overflow
            
            // If mid squared equals x, return mid as the exact square root
            if (square == x) {
                return mid;
            } 
            // If mid squared is less than x, update ans and move to the right half
            else if (square < x) {
                ans = mid;  // Store the possible answer
                start = mid + 1;
            } 
            // If mid squared is greater than x, move to the left half
            else {
                end = mid - 1;
            }
        }
        // Return the floor value of the square root if it's not a perfect square
        return ans;
    }
};

int main() {
    int x;
    
    // Prompt user for input
    cout << "Enter a number: ";
    cin >> x;
    
    // Create an instance of the Solution class
    Solution s1;
    
    // Call the mySqrt function and store the result
    int result = s1.mySqrt(x);

    // Display the computed integer square root
    cout << "Square root of " << x << " is: " << result << endl;

    return 0;
}
