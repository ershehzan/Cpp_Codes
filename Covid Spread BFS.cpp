#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    int row[4] = {-1, 1, 0, 0};
    int col[4] = {0, 0, -1, 1};
    int r, c;

    bool valid(int i, int j)
    {
        return i >= 0 && i < r && j >= 0 && j < c;
    }

    int helpaterp(vector<vector<int>> hospital)
    {
        r = hospital.size();
        c = hospital[0].size();

        queue<pair<int, int>> q;
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                if (hospital[i][j] == 2)
                    q.push({i, j});

        int timer = 0;
        while (!q.empty())
        {
            int curr_p = q.size();
            bool spread = false;

            while (curr_p--)
            {
                int i = q.front().first;
                int j = q.front().second;
                q.pop();

                for (int k = 0; k < 4; k++)
                {
                    int ni = i + row[k];
                    int nj = j + col[k];
                    if (valid(ni, nj) && hospital[ni][nj] == 1)
                    {
                        hospital[ni][nj] = 2;
                        q.push({ni, nj});
                        spread = true;
                    }
                }
            }
            if (spread)
                timer++;
        }

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (hospital[i][j] == 1)
                {
                    return -1;
                }
            }
        }
        return timer;
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> hospital(n, vector<int>(m));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> hospital[i][j];

    Solution sol;
    int result = sol.helpaterp(hospital);
    cout << result << endl;
    return 0;
}