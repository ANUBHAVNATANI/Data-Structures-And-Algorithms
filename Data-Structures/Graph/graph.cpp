//implementations of graph using stl
//using adjacency list representation
#include <bits/stdc++.h>
using namespace std;
//adding edge to a graph
//undirected
void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
//dfs function
void dfsinit(int u, vector<int> adj[], vector<bool> &visited)
{
    visited[u] == true;
    cout << "hello" << " ";
    for (int i = 0; i < adj[u].size(); i++)
    {
        if (visited[adj[u][i]] == false)
        {
            dfsinit(adj[u][i], adj, visited);
        }
    }
}
//dfs recurse code
void dfs(vector<int> adj[], int V)
{
    vector<bool> visited(V, false);
    for (int u = 0; u < V; u++)
    {
        if (visited[u] == false)
        {
            dfsinit(u, adj, visited);
        }
    }
}
//driver code
int main()
{
    int V = 4;
    vector<int> adj[V];
    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 2, 3);
    dfs(adj, V);
    return 0;
}