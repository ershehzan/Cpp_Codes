#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    int row[8] = {2, 2, -2, -2, 1, -1, 1, -1};
    int col[8] = {1, -1, 1, -1, 2, 2, -2, -2};

    bool valid(int i, int j, int n)
    {
        return i >= 0 && i < n && j >= 0 && j < n;
    }
    int minStepToReachTarget(vector<int> &KnightPos, vector<int> &TargetPos, int N)
    {

        KnightPos[0]--;
        KnightPos[1]--;
        TargetPos[0]--;
        TargetPos[1]--;

        if (KnightPos[0] == TargetPos[0] && KnightPos[1] == TargetPos[1])
            return 0;
        queue<pair<int, int>> q;
        vector<vector<bool>> chess(N, vector<bool>(N, 0));
        q.push({KnightPos[0], KnightPos[1]});
        chess[KnightPos[0]][KnightPos[1]] = 1;
        int step = 0;

        while (!q.empty())
        {
            int count = q.size();
            while (count--)
            {
                int i = q.front().first;
                int j = q.front().second;
                q.pop();

                for (int k = 0; k < 8; k++)
                {
                    int ni = i + row[k];
                    int nj = j + col[k];

                    if (ni == TargetPos[0] && nj == TargetPos[1])
                        return step + 1;

                    if (valid(ni, nj, N) && !chess[ni][nj])
                    {
                        chess[ni][nj] = 1;
                        q.push({ni, nj});
                    }
                }
            }
            step++;
        }
        return -1;
    }
};

int main()
{
    int N;
    cout << "Enter board size N: ";
    cin >> N;
    vector<int> KnightPos(2), TargetPos(2);
    cout << "Enter Knight's position (row col): ";
    cin >> KnightPos[0] >> KnightPos[1];
    cout << "Enter Target's position (row col): ";
    cin >> TargetPos[0] >> TargetPos[1];

    Solution sol;
    int steps = sol.minStepToReachTarget(KnightPos, TargetPos, N);
    cout << "Minimum steps: " << steps << endl;
    return 0;
}