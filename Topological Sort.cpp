#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
  void DFS(int node, vector<bool>& vis, vector<int> adj[], stack<int>& s) {
      vis[node] = 1;
      for (int j = 0; j < adj[node].size(); j++) {
          if (!vis[adj[node][j]])
              DFS(adj[node][j], vis, adj, s);
      }
      s.push(node);
  }

  vector<int> topoSort(int V, vector<vector<int>>& edges) {
      vector<int> adj[V];
      for (auto e : edges) {
          int u = e[0], v = e[1];
          adj[u].push_back(v);  // directed edge only
      }

      vector<bool> vis(V, 0);
      stack<int> s;

      for (int i = 0; i < V; i++) {
          if (!vis[i]) {
              DFS(i, vis, adj, s);
          }
      }

      vector<int> ans;
      while (!s.empty()) {
          ans.push_back(s.top());
          s.pop();
      }
      return ans;
  }
};

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<vector<int>> edges;
    cout << "Enter edges (u v) for directed graph:\n";
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
    }

    Solution obj;
    vector<int> topo = obj.topoSort(V, edges);

    cout << "Topological Sort: ";
    for (int node : topo) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
