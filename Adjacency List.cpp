#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// Undirected Graph using Adjacency Matrix

int main(){
    
    int vertex, edges;
    cout << "Enter number of vertices and edges: ";
    cin >> vertex >> edges;

    vector<int> list[vertex];
    int u, v;

    for (int i = 0; i < edges; i++)
    {
        cin >> u >> v;
        list[u].push_back(v);
        list[v].push_back(u);
    }
    cout << "Adjacency Matrix:" << endl;
    for (int i = 0; i < vertex; i++){
        cout<<i<<"->";
        // Print the adjacency list for vertex i
        for (size_t j = 0; j < list[i].size(); j++)
        {
            cout << list[i][j] << " ";
        }
        cout << endl;
    }
}




