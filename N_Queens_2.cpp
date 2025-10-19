#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void find(int row, int n, int &ans, vector<bool>& column, vector<bool>& RD, vector<bool>& LD) {
        if (row == n) {
            ans++;
            return;
        }
        for (int j = 0; j < n; j++) {
            if (column[j] == 0 && LD[n - 1 + j - row] == 0 && RD[row + j] == 0) {
                column[j] = 1;
                LD[n - 1 + j - row] = 1;
                RD[row + j] = 1;
                find(row + 1, n, ans, column, RD, LD);
                column[j] = 0;
                LD[n - 1 + j - row] = 0;
                RD[row + j] = 0;
            }
        }
    }
    int totalNQueens(int n) {
        if (n == 1)
            return 1;
        int ans = 0;
        vector<bool> column(n, 0);
        vector<bool> RD(2 * n - 1);
        vector<bool> LD(2 * n - 1);
        find(0, n, ans, column, RD, LD);
        return ans;
    }
};

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    Solution sol;
    int result = sol.totalNQueens(n);
    cout << "Total solutions for " << n << "-Queens: " << result << endl;
    return 0;
}