#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// User function Template for C++
class Solution{
public:
    int row[4] = {1, -1, 0, 0};
    int col[4] = {0, 0, 1, -1};

    bool valid(int i, int j, int n, int m)
    {
        return i >= 0 && j >= 0 && i < n && j < m;
    }

    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y)
    {
        if (A[0][0] == 0)
            return -1; // start blocked
        if (X == 0 && Y == 0)
            return 0;
        if (A[X][Y] == 0)
            return -1; // destination blocked

        queue<pair<int, int>> q;
        q.push({0, 0});
        A[0][0] = 0; // mark visited
        int step = 0;

        while (!q.empty())
        {
            int count = q.size();
            while (count--)
            {
                auto [i, j] = q.front();
                q.pop();

                for (int k = 0; k < 4; k++)
                {
                    int ni = i + row[k];
                    int nj = j + col[k];

                    if (ni == X && nj == Y)
                        return step + 1;

                    if (valid(ni, nj, N, M) && A[ni][nj] == 1)
                    {
                        A[ni][nj] = 0; // mark visited
                        q.push({ni, nj});
                    }
                }
            }
            step++;
        }
        return -1;
    }
};

int main(){
    int N, M;
    cout << "Enter number of rows and columns: ";
    cin >> N >> M;
    vector<vector<int>> A(N, vector<int>(M));
    cout << "Enter the grid (0 for blocked, 1 for open):\n";
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            cin >> A[i][j];
    int X, Y;
    cout << "Enter destination coordinates (X Y): ";
    cin >> X >> Y;

    Solution sol;
    int result = sol.shortestDistance(N, M, A, X, Y);
    cout << "Shortest Distance: " << result << endl;
    return 0;

}

