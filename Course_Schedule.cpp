#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    vector<int> findOrder(int n, vector<vector<int>> prerequisites)
    {
        vector<int> Indeg(n, 0);
        vector<int> adj[n];
        for (auto &p : prerequisites)
        {
            int u = p[0];
            int v = p[1];
            adj[v].push_back(u);
            Indeg[u]++;
        }
        queue<int> q;
        for (int i = 0; i < n; i++)
        {
            if (Indeg[i] == 0)
                q.push(i);
        }
        vector<int> ans;

        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            ans.push_back(node);

            for (int j = 0; j < adj[node].size(); j++)
            {
                Indeg[adj[node][j]]--;
                if (Indeg[adj[node][j]] == 0)
                    q.push(adj[node][j]);
            }
        }
        vector<int> temp;
        return ans.size() == n ? ans : temp;
    }
};

int main()
{
    int n, m;
    cout << "Enter number of courses and number of prerequisites: ";
    cin >> n >> m;
    vector<vector<int>> prerequisites(m, vector<int>(2));
    cout << "Enter prerequisites (course prerequisite):\n";
    for (int i = 0; i < m; ++i)
    {
        cin >> prerequisites[i][0] >> prerequisites[i][1];
    }
    Solution sol;
    vector<int> order = sol.findOrder(n, prerequisites);
    if (order.empty())
    {
        cout << "No possible order to finish all courses.\n";
    }
    else
    {
        cout << "One possible order to finish all courses: ";
        for (int course : order)
        {
            cout << course << " ";
        }
        cout << endl;
    }
    return 0;
}