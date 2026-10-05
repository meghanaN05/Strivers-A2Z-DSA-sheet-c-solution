#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  bool bfs(int i, int parent, vector<int> &vis, vector<vector<int>> &adj)
  {
    vis[i] = 1;
    queue<pair<int, int>> q;
    q.push({i, -1});
    while (!q.empty())
    {
      int node = q.front().first;
      int parent = q.front().second;
      q.pop();
      for (int neigh : adj[node])
      {
        if (!vis[neigh])
        {
          vis[neigh] = 1;
          q.push({neigh, node});
        }
        else
        {
          if (neigh != parent)
            return true;
        }
      }
    }
    return false;
  }
  bool isCycle(int V, vector<vector<int>> &edges)
  {
    // Code here
    vector<vector<int>> adj(V);
    for (auto &e : edges)
    {
      int u = e[0];
      int v = e[1];
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    vector<int> vis(V, 0);
    for (int i = 0; i < V; i++)
    {
      if (!vis[i])
      {
        if (bfs(i, -1, vis, adj))
          return true;
      }
    }
    return false;
  }
};