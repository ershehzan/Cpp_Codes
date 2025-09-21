#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    int r;
    int c;
    bool valid(int i, int j)
    {
        return i >= 0 && i < r && j >= 0 && j < c;
    }
    int row[8] = {-1, -1, -1, 1, 1, 1, 0, 0};
    int col[8] = {-1, 0, 1, -1, 0, 1, -1, 1};

    int countIslands(vector<vector<char>> &grid)
    {
        r = grid.size();
        c = grid[0].size();

        queue<pair<int, int>> q;
        int count = 0;
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (grid[i][j] == 'L')
                {
                    count++;
                    q.push({i, j});
                    grid[i][j] = 'W';

                    while (!q.empty())
                    {
                        int i = q.front().first;
                        int j = q.front().second;
                        q.pop();

                        for (int k = 0; k < 8; k++)
                        {
                            int ni = i + row[k];
                            int nj = j + col[k];

                            if (valid(ni, nj) && grid[ni][nj] == 'L')
                            {
                                grid[ni][nj] = 'W';
                                q.push({ni, nj});
                            }
                        }
                    }
                }
            }
        }
        return count;
    }
};

int main()
{
    int n, m;
    cout << "Enter number of rows and columns: ";
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));
    cout << "Enter the grid (L for land, W for water):\n";
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> grid[i][j];
        }
    }
    Solution sol;
    int islands = sol.countIslands(grid);
    cout << "Number of islands: " << islands << endl;
    return 0;
}