#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    bool isPossible(vector<int>& target) {
        // Max heap to always get the largest number
        priority_queue<long long> p;
        long long sum = 0;

        for (int num : target) {
            p.push(num);
            sum += num;
        }

        while (p.top() != 1) {
            long long maxEle = p.top(); p.pop();
            long long restSum = sum - maxEle;

            // Edge cases
            if (restSum == 0 || maxEle <= restSum)
                return false;

            long long prev = maxEle % restSum;

            // If mod result is 0, we can only proceed if restSum == 1
            if (prev == 0) {
                return restSum == 1;
            }

            // Update total sum and push back the new element
            sum = restSum + prev;
            p.push(prev);
        }

        return true;
    }
};

int main() {
    Solution sol;

    // Example test cases
    vector<int> target1 = {9, 3, 5};
    vector<int> target2 = {1, 1, 1, 2};
    vector<int> target3 = {8, 5};

    cout << "Test Case 1: " << (sol.isPossible(target1) ? "true" : "false") << endl;
    cout << "Test Case 2: " << (sol.isPossible(target2) ? "true" : "false") << endl;
    cout << "Test Case 3: " << (sol.isPossible(target3) ? "true" : "false") << endl;

    return 0;
}
