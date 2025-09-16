#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Solution class implementation
class Solution {
public:
    bool BFS(int vertex, vector<int> adj[], vector<bool>& vis) {
        vis[vertex] = 1;
        queue<pair<int, int>> q;
        q.push({vertex, -1});

        while (!q.empty()) {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();

            for (int j = 0; j < adj[node].size(); j++) {
                int N = adj[node][j];

                if (N == parent)
                    continue;

                if (vis[N])  // Already visited → cycle detected
                    return true;

                vis[N] = 1;
                q.push({N, node});
            }
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
            if (!vis[i] && BFS(i, adj, vis))
                return true;
        }

        return false;
    }
};

int main() {
    int V = 4;  // Number of vertices
    vector<vector<int>> edges = {
        {0, 1},
        {1, 2},
        {2, 3},
        {3, 1}  // This edge creates a cycle
    };

    Solution solution;
    if (solution.isCycle(V, edges)) {
        cout << "Graph contains a cycle." << endl;
    } else {
        cout << "Graph does not contain a cycle." << endl;
    }

    return 0;
}
