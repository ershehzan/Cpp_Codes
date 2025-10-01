#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:

    void DFS(int node, vector<int> adj[], vector<bool> &vis)
    {
        vis[node] = 1;
        for (int j = 0; j < adj[node].size(); j++)
        {
            if (!vis[adj[node][j]])
                DFS(adj[node][j], adj, vis);
        }
    }
    int isEulerCircuit(int V, vector<int> adj[])
    {
        vector<int> deg(V, 0);
        int odd_deg = 0;
        for (int i = 0; i < V; i++)
        {
            deg[i] = adj[i].size();
            if (deg[i] % 2)
                odd_deg++;
        }
        if (odd_deg != 2 && odd_deg != 0)
            return 0;

        vector<bool> vis(V, 0);
        for (int i = 0; i < V; i++)
        {
            if (deg[i])
            {
                DFS(i, adj, vis);
                break;
            }
        }
        for (int i = 0; i < V; i++)
        {
            if (deg[i] && !vis[i])
            {
                return 0;
            }
        }
        if (odd_deg == 0)
        {
            return 2;
        }
        else
        {
            return 1;
        }
    }
};

int main(){
    
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;
    vector<int> adj[V];
    cout << "Enter edges (u v):" << endl;
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // undirected graph
    }
    
    Solution sol;
    int res = sol.isEulerCircuit(V, adj);
    if (res == 2)
        cout << "Graph has an Euler Circuit" << endl;
    else if (res == 1)
        cout << "Graph has an Euler Path" << endl;
    else
        cout << "Graph is not Eulerian" << endl;
    return 0;

}




