#include <iostream>
using namespace std;

class Solution {
public:
    int findMin(int n) {
        int currency[] = {10, 5, 2, 1};
        int ans = 0;

        for (int i = 0; i < 4 && n > 0; i++) {
            ans += n / currency[i];
            n %= currency[i];
        }
        return ans;
    }
};

int main() {
    int n;
    cout << "Enter amount: ";
    cin >> n;

    Solution sol;
    cout << "Minimum number of coins required: " << sol.findMin(n) << endl;

    return 0;
}
