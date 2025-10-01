#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void DFS(int node, vector<vector<int>> &adj, vector<int> &ans, vector<bool> &vis)
    {
        vis[node] = true;
        ans.push_back(node);

        for (int j = 0; j < adj[node].size(); j++)
        {
            if (!vis[adj[node][j]])
            {
                DFS(adj[node][j], adj, ans, vis);
            }
        }
    }

    vector<int> dfs(vector<vector<int>> &adj)
    {
        vector<bool> vis(adj.size(), false);
        vector<int> ans;

        DFS(0, adj, ans, vis);

        return ans;
    }
};

int main()
{
    // Example graph: 0-1, 0-2, 1-3, 1-4
    vector<vector<int>> adj = {
        {1, 2},    // neighbors of node 0
        {0, 3, 4}, // neighbors of node 1
        {0},       // neighbors of node 2
        {1},       // neighbors of node 3
        {1}        // neighbors of node 4
    };

    Solution sol;
    vector<int> traversal = sol.dfs(adj);

    cout << "DFS Traversal: ";
    for (int node : traversal)
    {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}