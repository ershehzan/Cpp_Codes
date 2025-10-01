#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> bellmanFord(int V, vector<vector<int>> &edges, int src)
    {
        vector<int> dist(V, 1e8);
        dist[src] = 0;
        int e = edges.size();

        for (int i = 0; i < V - 1; i++)
        {
            for (int j = 0; j < e; j++)
            {
                int u = edges[j][0];
                int v = edges[j][1];
                int wt = edges[j][2];

                if (dist[u] == 1e8)
                    continue;

                if (dist[u] + wt < dist[v])
                {
                    dist[v] = dist[u] + wt;
                }
            }
        }
        for (int j = 0; j < e; j++)
        {
            int u = edges[j][0];
            int v = edges[j][1];
            int wt = edges[j][2];

            if (dist[u] == 1e8)
                continue;

            if (dist[u] + wt < dist[v])
            {
                vector<int> ans;
                ans.push_back(-1);
                return ans;
            }
        }
        return dist;
    }
};

int main()
{
    int V, E, src;
    cout << "Enter number of vertices, edges and source vertex: ";
    cin >> V >> E >> src;
    vector<vector<int>> edges(E, vector<int>(3));
    cout << "Enter edges (u v wt):\n";
    for (int i = 0; i < E; i++)
    {
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    }
    Solution sol;
    vector<int> result = sol.bellmanFord(V, edges, src);
    cout << "Shortest distances from source " << src << ":\n";
    for (int i = 0; i < result.size(); i++)
    {
        if (result[i] == 1e8)
            cout << "INF ";
        else
            cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}