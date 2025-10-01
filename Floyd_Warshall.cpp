#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

class Solution
{
public:
    void floydWarshall(vector<vector<int>> &dist)
    {
        int n = dist.size();
        for (int k = 0; k < n; k++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (dist[i][k] == 1e8 || dist[k][j] == 1e8)
                        continue;
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
};

int main()
{

    int n;
    cout << "Enter number of vertices: ";
    cin >> n;
    vector<vector<int>> dist(n, vector<int>(n));
    cout << "Enter adjacency matrix (use 1e8 for no edge):\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> dist[i][j];
        }
    }

    Solution sol;
    sol.floydWarshall(dist);

    cout << "Shortest distances matrix:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (dist[i][j] == 1e8)
                cout << "INF ";
            else
                cout << dist[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}