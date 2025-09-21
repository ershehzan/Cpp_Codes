#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    int r, c;
    int row[4] = {1, -1, 0, 0};
    int col[4] = {0, 0, 1, -1};

    bool valid(int i, int j)
    {
        return i >= 0 && i < r && j >= 0 && j < c;
    }

    vector<vector<char>> fill(vector<vector<char>> &mat)
    {

        r = mat.size();
        c = mat[0].size();

        queue<pair<int, int>> q;

        // First row
        for (int j = 0; j < c; j++)
        {
            if (mat[0][j] == 'O')
            {
                q.push({0, j});
                mat[0][j] = 'T';
            }
        }
        // First col
        for (int i = 0; i < r; i++)
        {
            if (mat[i][0] == 'O')
            {
                q.push({i, 0});
                mat[i][0] = 'T';
            }
        }
        // Last row
        for (int j = 0; j < c; j++)
        {
            if (mat[r - 1][j] == 'O')
            {
                q.push({r - 1, j});
                mat[r - 1][j] = 'T';
            }
        }
        // Last col
        for (int i = 0; i < r; i++)
        {
            if (mat[i][c - 1] == 'O')
            {
                q.push({i, c - 1});
                mat[i][c - 1] = 'T';
            }
        }

        // BFS to mark connected O’s
        while (!q.empty())
        {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();

            for (int k = 0; k < 4; k++)
            {
                int ni = i + row[k];
                int nj = j + col[k];

                if (valid(ni, nj) && mat[ni][nj] == 'O')
                {
                    mat[ni][nj] = 'T';
                    q.push({ni, nj});
                }
            }
        }

        // Final pass: convert O->X, T->O
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (mat[i][j] == 'O')
                {
                    mat[i][j] = 'X';
                }
                else if (mat[i][j] == 'T')
                {
                    mat[i][j] = 'O';
                }
            }
        }
        return mat;
    }
};

int main()
{
    int n, m;
    cout << "Enter number of rows and columns: ";
    cin >> n >> m;
    vector<vector<char>> mat(n, vector<char>(m));
    cout << "Enter the matrix (O/X):\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mat[i][j];
        }
    }
    Solution sol;
    vector<vector<char>> res = sol.fill(mat);
    cout << "Resultant matrix:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}