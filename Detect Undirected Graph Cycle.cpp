#include <iostream>
#include <vector>
using namespace std;

// Your Solution class definition here
class Solution {
public:
    bool DC(int node, int parent, vector<int> adj[], vector<bool>& vis) {
        vis[node] = 1;

        for (int j = 0; j < adj[node].size(); j++) {
            int N = adj[node][j];

            if (parent == N)
                continue;

            if (vis[N] == 1)
                return true;

            if (DC(N, node, adj, vis))
                return true;
        }
        return false;
    }

    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<bool> vis(V, 0);
        vector<int> adj[V];
        for (auto e : edges) {
            int u = e[0], v = e[1];
            adj[v].push_back(u);
            adj[u].push_back(v);
        }

        for (int i = 0; i < V; i++) {
            if (!vis[i] && DC(i, -1, adj, vis)) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    int V = 5;  // Number of vertices
    vector<vector<int>> edges = {
        {0, 1},
        {1, 2},
        {2, 3},
        {3, 4},
        {4, 1}  // This edge creates a cycle
    };

    Solution solution;
    if (solution.isCycle(V, edges)) {
        cout << "Graph contains a cycle." << endl;
    } else {
        cout << "Graph does not contain a cycle." << endl;
    }

    return 0;
}
