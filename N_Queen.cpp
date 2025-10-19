#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void find(int row, int n, vector<vector<string>>& ans, vector<string>& board, vector<bool>& column, vector<bool>& RD, vector<bool>& LD) {
        if (row == n) {
            ans.push_back(board);
            return;
        }
        for (int j = 0; j < n; j++) {
            if (column[j] == 0 && LD[n - 1 + j - row] == 0 && RD[row + j] == 0) {
                column[j] = 1;
                board[row][j] = 'Q';
                LD[n - 1 + j - row] = 1;
                RD[row + j] = 1;
                find(row + 1, n, ans, board, column, RD, LD);
                column[j] = 0;
                board[row][j] = '.';
                LD[n - 1 + j - row] = 0;
                RD[row + j] = 0;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        vector<bool> column(n, 0);
        vector<bool> RD(2 * n - 1, 0);
        vector<bool> LD(2 * n - 1, 0);
        find(0, n, ans, board, column, RD, LD);
        return ans;
    }
};

int main() {
    int n;
    cout << "Enter the value of N: ";
    cin >> n;
    Solution sol;
    vector<vector<string>> solutions = sol.solveNQueens(n);
    cout << "Number of solutions: " << solutions.size() << endl;
    for (const auto& board : solutions) {
        for (const auto& row : board) {
            cout << row << endl;
        }
        cout << endl;
    }
    return 0;
}