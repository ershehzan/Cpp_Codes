#include <bits/stdc++.h>
using namespace std;

// Paste your Solution class here
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Build adjacency list
        vector<vector<pair<int,int>>> adj(V);
        for (auto &e : edges) 
        {
            int u = e[0], v = e[1], w = e[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w}); // remove this if graph is directed
        }
        
        vector<int> dist(V, INT_MAX);
        vector<bool> explored(V, 0);
        dist[src] = 0;

        // Min-heap: (distance, node)
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, src});

        while (!pq.empty())
        {
            int node = pq.top().second;
            pq.pop();

            if (explored[node])
                continue;
            explored[node] = 1;

            // Relax all neighbors
            for (auto &edge : adj[node])
            {
                int neigh = edge.first;
                int weight = edge.second;

                if (!explored[neigh] && dist[neigh] > dist[node] + weight) {
                    dist[neigh] = dist[node] + weight;
                    pq.push({dist[neigh], neigh});
                }
            }
        }

        return dist;
    }
};

int main() {
    int V, E, src;
    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> E;

    vector<vector<int>> edges(E, vector<int>(3));
    cout << "Enter edges (u v w):" << endl;
    for (int i = 0; i < E; i++) {
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    }

    cout << "Enter source node: ";
    cin >> src;

    Solution sol;
    vector<int> dist = sol.dijkstra(V, edges, src);

    cout << "Shortest distances from node " << src << ":\n";
    for (int i = 0; i < V; i++) {
        if (dist[i] == INT_MAX)
            cout << i << " : INF\n";
        else
            cout << i << " : " << dist[i] << "\n";
    }

    return 0;
}
