
//BFS approach to find the shortest path in an unweighted undirected graph
//Time Complexity: O(N + E) where N is the number of nodes and E is
#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<int> shortestPath(vector<vector<int>> &adj, int src)
    {
        int n = adj.size();
        vector<int> dist(n, -1);
        vector<bool> vis(n, 0);

        queue<int> q;
        q.push(src);
        dist[src] = 0;
        vis[src] = 1;

        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            for (int j = 0; j < adj[node].size(); j++)
            {
                if (vis[adj[node][j]])
                    continue;

                vis[adj[node][j]] = 1;
                q.push(adj[node][j]);
                dist[adj[node][j]] = dist[node] + 1;
            }
        }
        return dist;
    }
};

int main()
{
    int n, m;
    cin >> n >> m; // number of nodes and edges

    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        // undirected graph
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int src;
    cin >> src;

    Solution obj;
    vector<int> ans = obj.shortestPath(adj, src);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << "\n";

    return 0;
}

