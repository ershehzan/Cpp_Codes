#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int rotationCount(long long R, long long D) {
        int ans = 0;
        int first, sec;

        while (R) {
            first = R % 10;
            sec = D % 10;
            R /= 10;
            D /= 10;
            ans += min(abs(first - sec), 10 - abs(first - sec));
        }
        return ans;
    }
};

int main() {
    Solution obj;
    long long R, D;
    cin >> R >> D;  // Input two numbers

    cout << obj.rotationCount(R, D) << endl;

    return 0;
}
