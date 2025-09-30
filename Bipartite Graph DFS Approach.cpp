#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    bool DFS(int node, vector<int> adj[], vector<int> &color)
    {
        for (int neigh : adj[node])
        {
            if (color[neigh] == -1)
            {
                color[neigh] = (color[node] + 1) % 2;
                if (!DFS(neigh, adj, color))
                    return 0;
            }
            else
            {
                if (color[neigh] == color[node])
                    return 0;
            }
        }
        return 1;
    }

    bool isBipartite(int V, vector<vector<int>> &edges)
    {
        vector<int> adj[V];
        for (auto e : edges)
        {
            int v = e[0], u = e[1];
            adj[v].push_back(u);
            adj[u].push_back(v);
        }
        vector<int> color(V, -1);
        // Handle disconnected graphs
        for (int i = 0; i < V; ++i)
        {
            if (color[i] == -1)
            {
                color[i] = 0;
                if (!DFS(i, adj, color))
                    return false;
            }
        }
        return true;
    }
};

int main(){
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;
    vector<vector<int>> edges;
    cout << "Enter edges (u v):" << endl;
    for (int i = 0; i < E; ++i)
    {
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
    }
    Solution sol;
    if (sol.isBipartite(V, edges))
        cout << "Graph is Bipartite" << endl;
    else
        cout << "Graph is NOT Bipartite" << endl;
    return 0;

}

