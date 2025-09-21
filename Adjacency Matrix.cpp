#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// Undirected Graph using Adjacency Matrix
int main()
{
    int vertex, edges;
    cout << "Enter number of vertices and edges: ";
    cin >> vertex>>edges;
    
    vector<vector<bool>> adjmat(vertex, vector<bool>(vertex, 0));
    int u, v;

    for (int i = 0; i < edges; i++)
    {
        cin >> u >> v;
        adjmat[u][v] = 1;
        adjmat[v][u] = 1; // Since the graph is undirected
    }
    cout << "Adjacency Matrix:" << endl;
    for(int i=0;i<vertex;i++)
    {
        for(int j=0;j<vertex;j++)
        {
            cout<<adjmat[i][j]<<" ";
            
        }
        cout<<endl;
    }
}