#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<int> adj[V];
        
        for (auto e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
        }
        
        queue<int> q;
        vector<int> InDeg(V, 0);
        vector<int> ans;
        
        for (int i = 0; i < V; i++)
            for (int j = 0; j < adj[i].size(); j++)
                InDeg[adj[i][j]]++;
            
        for (int i = 0; i < V; i++) {
            if (InDeg[i] == 0)
                q.push(i);
        }
        
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            
            for (int j = 0; j < adj[node].size(); j++) {
                InDeg[adj[node][j]]--;
                if (InDeg[adj[node][j]] == 0)
                    q.push(adj[node][j]);
            }
        }
        
        return ans;
    }
};

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<vector<int>> edges;
    cout << "Enter directed edges (u v):\n";
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
    }

    Solution obj;
    vector<int> topo = obj.topoSort(V, edges);

    cout << "Topological Sort Order: ";
    for (int node : topo) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
