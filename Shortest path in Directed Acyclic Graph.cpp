#include <iostream>
#include <vector>
#include <stack>
#include <climits>
using namespace std;

// User function Template for C++
class Solution{
public:
    void DFS(int node, vector<pair<int, int>> adj[], stack<int> &s, vector<bool> &vis)
    {
        vis[node] = 1;
        for (int j = 0; j < adj[node].size(); j++)
        {
            if (!vis[adj[node][j].first])
                DFS(adj[node][j].first, adj, s, vis);
        }
        s.push(node);
    }

    vector<int> shortestPath(int V, int E, vector<vector<int>> &edges) {
        vector<pair<int, int>> adj[V];
        for (int i = 0; i < E; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int weight = edges[i][2];
            adj[u].push_back(make_pair(v, weight));
        }
        stack<int> s;
        vector<bool> vis(V, 0);
        DFS(0, adj, s, vis);
        vector<int> dist(V, INT_MAX);
        dist[0] = 0;
        while (!s.empty())
        {
            int node = s.top();
            s.pop();
            if (dist[node] != INT_MAX)
            {
                for (int j = 0; j < adj[node].size(); j++)
                {
                    int neigh = adj[node][j].first;
                    int weight = adj[node][j].second;
                    if (dist[node] + weight < dist[neigh])
                        dist[neigh] = weight + dist[node];
                }
            }
        }
        for (int i = 0; i < V; i++)
        {
            if (dist[i] == INT_MAX)
                dist[i] = -1;
        }
        return dist;
    }
};

int main()
{
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;
    vector<vector<int>> edges(E, vector<int>(3));
    cout << "Enter edges (u v w) one per line:\n";
    for (int i = 0; i < E; ++i)
    {
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    }
    Solution sol;
    vector<int> result = sol.shortestPath(V, E, edges);
    cout << "Shortest distances from node 0:\n";
    for (int i = 0; i < V; ++i)
    {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}