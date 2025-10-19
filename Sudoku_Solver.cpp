#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool check(int n, vector<vector<char>>& board, int i, int j) {
        char c = '0' + n;
        // check Row
        for (int col = 0; col < 9; col++) {
            if (board[i][col] == c)
                return 0;
        }
        // check Col
        for (int row = 0; row < 9; row++) {
            if (board[row][j] == c)
                return 0;
        }
        // check at same box
        int row = (i / 3) * 3, col = (j / 3) * 3;
        for (int a = row; a < row + 3; a++) {
            for (int b = col; b < col + 3; b++) {
                if (board[a][b] == c)
                    return 0;
            }
        }
        return 1;
    }
    bool find(int i, int j, vector<vector<char>>& board) {
        if (i == 9)
            return 1;
        if (j == 9)
            return find(i + 1, 0, board);
        if (board[i][j] != '.')
            return find(i, j + 1, board);
        for (int n = 1; n <= 9; n++) {
            if (check(n, board, i, j)) {
                board[i][j] = '0' + n;
                if (find(i, j + 1, board))
                    return 1;
                board[i][j] = '.';
            }
        }
        return 0;
    }
    void solveSudoku(vector<vector<char>>& board) {
        find(0, 0, board);
    }
};

int main() {
    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    Solution sol;
    sol.solveSudoku(board);

    for (const auto& row : board) {
        for (const auto& c : row) {
            cout << c << " ";
        }
        cout << endl;
    }
    return 0;
}