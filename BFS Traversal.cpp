#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfs(vector<vector<int>> &adj)
    {
        queue<int> q;
        q.push(0);
        vector<bool> visited(adj.size(), 0);
        visited[0] = 1;
        vector<int> ans;
        int node;

        while (!q.empty())
        {
            node = q.front();
            q.pop();
            ans.push_back(node);
            for (int j = 0; j < adj[node].size(); j++)
            {
                if (!visited[adj[node][j]])
                {
                    visited[adj[node][j]] = 1;
                    q.push(adj[node][j]);
                }
            }
        }
        return ans;
    }
};

int main()
{
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;
    vector<vector<int>> adj(V);
    cout << "Enter edges (u v):" << endl;
    for (int i = 0; i < E; ++i)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // For undirected graph
    }

    Solution sol;
    vector<int> traversal = sol.bfs(adj);

    cout << "BFS Traversal: ";
    for (int node : traversal)
    {
        cout << node << " ";
    }
    cout << endl;

    return 0;

}





