#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  bool dfs(int v, vector<vector<int>> &adj,
           vector<bool> &visited, int parent)
  {
    visited[v] = true;

    for (int i : adj[v])
    {
      if (!visited[i])
      {
        if (dfs(i, adj, visited, v))
          return true;
      }
      else if (i != parent)
      {
        return true;
      }
    }

    return false;
  }

  bool isCycle(int V, vector<vector<int>> &edges)
  {

    vector<vector<int>> adj(V);
    for (auto edge : edges)
    {
      int u = edge[0];
      int v = edge[1];

      adj[u].push_back(v);
      adj[v].push_back(u);
    }

    vector<bool> visited(V, false);
    for (int i = 0; i < V; i++)
    {
      if (!visited[i])
      {
        if (dfs(i, adj, visited, -1))
          return true;
      }
    }

    return false;
  }
};