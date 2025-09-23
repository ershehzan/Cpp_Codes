#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    bool isPossible(int N, int P, vector<pair<int, int>> &prerequisites)
    {
        vector<int> Indeg(N, 0);
        queue<int> q;
        vector<int> adj[N];
        for (auto &p : prerequisites)
        {
            int u = p.second;
            int v = p.first;
            adj[u].push_back(v);
            Indeg[v]++;
        }
        for (int j = 0; j < N; j++)
        {
            if (!Indeg[j])
                q.push(j);
        }
        int count = 0;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            count++;
            for (int j = 0; j < adj[node].size(); j++)
            {
                Indeg[adj[node][j]]--;
                if (!Indeg[adj[node][j]])
                    q.push(adj[node][j]);
            }
        }
        return count == N;
    }
};

int main()
{
    int N, P;
    cout << "Enter number of tasks (N) and prerequisites (P): ";
    cin >> N >> P;
    vector<pair<int, int>> prerequisites;
    cout << "Enter each prerequisite pair (a b) meaning b is prerequisite for a:\n";
    for (int i = 0; i < P; ++i)
    {
        int a, b;
        cin >> a >> b;
        prerequisites.push_back({a, b});
    }
    Solution sol;
    if (sol.isPossible(N, P, prerequisites))
    {
        cout << "Yes, it is possible to finish all tasks.\n";
    }
    else
    {
        cout << "No, it is not possible to finish all tasks.\n";
    }
    return 0;
}